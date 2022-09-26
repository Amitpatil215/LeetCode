class disjoint_set {
   private:
    int n;
    vector<int> Parent;
    vector<int> Rank;

    void initilaize_parent() {
        for (int i = 0; i < n; i++) {
            Parent[i] = i;
        }
    }

   public:
    // constructor
    disjoint_set(int n) {
        this->n = n;
        Parent = vector<int>(n);
        initilaize_parent();
        Rank = vector<int>(n, 0);
    }

    int find_parent(int node) {
        if (Parent[node] == node) {
            return node;
        }

        // find parent recursively until the node is a parent of himself
        // and also a Path compression step
        return Parent[node] = find_parent(Parent[node]);
    }

    void union_sets(int u, int v) {
        // find parent of u and v
        u = find_parent(u);
        v = find_parent(v);

        // we attach to a node having higher rank
        // if rank is same then increase rank of any one of the
        // parent node and attach to it
        if (Rank[u] < Rank[v]) {
            Parent[u] = v;
        } else if (Rank[u] > Rank[v]) {
            Parent[v] = u;
        } else {
            Rank[u]++;
            Parent[v] = u;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        disjoint_set ds = disjoint_set(26);
        for(auto eq: equations){
            char xi = eq[0];
            bool isEqual = eq[1]=='=';
            char yi = eq[3];
            
            if(!isEqual && xi==yi){
                return false;
            }
            if(isEqual){
                ds.union_sets(xi-'a',yi-'a');
            }
        }
        for(auto eq: equations){
            char xi = eq[0];
            bool isEqual = eq[1]=='=';
            char yi = eq[3];
            
            if(!isEqual){
                if(ds.find_parent(xi-'a')==ds.find_parent(yi-'a')){
                    return false;
                }
            }
        }
        return true;
    }
};