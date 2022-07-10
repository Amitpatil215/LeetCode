// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> edges[])
    {
        // build adjacecny list
        vector<pair<int,int>> adjList[v];
        
        for(int i=0;i<v;i++){
            for(auto edge:edges[i]){
                adjList[i].push_back({edge[0],edge[1]});
                adjList[edge[0]].push_back({i,edge[1]});
            }
        }
        
        // perform prims algo
        vector<int> dist(v,INT_MAX);
        vector<bool> mst(v,false);
        vector<int> parent(v,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minpq;
        
        
        dist[0] = 0;
        minpq.push({0,0});
        // as we gonna be having v-1 edges iterate for that no of times 
        while(!minpq.empty()){
            //choose minimum dist from dist array 
            int minNode = minpq.top().second;

            minpq.pop();
            // consider min node as mst
            mst[minNode] = true;
            
            // update the distance for its neighbours
            for(auto nbr: adjList[minNode]){
                int nbrNode = nbr.first;
                int nbrWeight = nbr.second;
                if( !mst[nbrNode] && nbrWeight < dist[nbrNode]){
                    dist[nbrNode] =   nbrWeight;
                    parent[nbrNode] = minNode;
                    minpq.push({nbrWeight, nbrNode});
                }
            }
            
        }
        // print edges
        // for(int i=1;i< v; i++){
        //     cout<<parent[i]<<"-"<<i <<"  "<<dist[i]<<endl;
        // }
        // cout<<endl;
        
        // find sum of weight
        int sum = 0 ;
        for(auto w:dist){
            sum+=w;
        }
        return sum;
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