// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class disjoint_set{
  private:
  int n;
  vector<int> Parent;
  vector<int> Rank;
  
  void initilaize_parent(){
    for(int i=0;i <n; i++){
        Parent[i] = i;
    }
  }
  
  public:
  disjoint_set(int n){
    this->n = n;
    Parent = vector<int>(n);
    initilaize_parent();
    Rank = vector<int>(n, 0);
  }
  
  int find_parent(int node){
    if(Parent[node] == node){
        return node;
    }
    
    // find parent recursively until the node is a parent of himself
    // and also a Path compression step
    return Parent[node] = find_parent(Parent[node]);
  }
  
  void union_sets(int u, int v){
    // find parent of u and v
    u = find_parent(u); 
    v = find_parent(v);
    
    // we attach to a node having higher rank
    // if rank is same then increase rank of any one of the 
    // parent node and attach to it
    if(Rank[u]<Rank[v]){
        Parent[u] =v;
    }else if(Rank[u] > Rank[v]){
        Parent[v] = u;
    }else{
        Rank[u]++;
        Parent[v] = u;
    }
  }
};

bool comp(vector<int>&a,vector<int>&b){
    return a[2] < b[2]; // sort according to weight
}

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // build an edge list not adjacency lsit
        vector<vector<int>> edgeList;
        for(int i=0; i<v; i++){
            for(auto x:adj[i]){
                vector<int> edge(3);
                edge[0] = i; // source
                edge[1] = x[0]; // destination
                edge[2] = x[1]; // weight
                edgeList.push_back(edge);
            }
        }
        
        // cout<<edgeList.size()<<endl;
        // sort according to weight to pick greedly
        sort(edgeList.begin(),edgeList.end(),comp);
        
        // pick edge with least weight
        // if they belong to different set then exclude
        // other wise consider in min spanning tree
        int cost = 0 ;
        
        disjoint_set ds = disjoint_set(v);
        
        for(auto edge: edgeList){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(ds.find_parent(u)!=ds.find_parent(v)){
                cost += wt;
                ds.union_sets(u,v);
            }
        }
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends