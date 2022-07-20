class Solution {
public:
    vector<int> TopoSort(int numCourses, vector<vector<int>>& prerequisites){
        // build adjaceny list
        vector<int> adjList[numCourses];
        for(auto pre:prerequisites){
            int u = pre[0];
            int v = pre[1];
            adjList[v].push_back(u);
        }
        
        // find indegree
        vector<int> indegree(numCourses,0);
        for(auto tuple: adjList){
            for(auto nbrs: tuple){
                indegree[nbrs]++;
            }
        }
        
        // push 0 indegree nodes to the queue
        queue<int>q;
        for(int i=0; i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int front =q.front();
            q.pop();
            ans.push_back(front);
            
            for(auto nbr:adjList[front]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        
        if(ans.size()==numCourses)  return ans;
        return vector<int>();
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       // if we able to find topo sort then it is possible otherwise not 
        return TopoSort(numCourses,prerequisites);
    }
};