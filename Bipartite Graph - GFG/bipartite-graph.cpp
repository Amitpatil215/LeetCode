// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isBipartiteBFS(int startNode, vector<int> adj[], vector<int>&colours ){
        queue<int> q;
        
        q.push(startNode);
        colours[startNode]=0; //0 ->Blue 1-> Green
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto nbr: adj[front]){
                if(colours[nbr]==-1){
                    // node is not eralier visited i.e coloured
                    // colour with opposite colour
                    // if parents colour is 1 then assign 0 otherwise 1
                    colours[nbr] = colours[front] == 1? 0 : 1;
                    q.push(nbr);
                }else{
                    // if alredy coloured then
                    // check if it has different colour than parent
                    // otherwise return false as we cant form a bipertite graph
                    if(colours[nbr]==colours[front]){
                        return false;
                    }
                }
            }
        }
        // if we able to colour component without any adjacent same colours 
        // then we have a bipertite graph
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> colours(V,-1);
        for(int i=0;i<V;i++){
            if(colours[i]==-1){
                if(!isBipartiteBFS(i,adj,colours)){
                    return false;
                }
            }
        }
        return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends