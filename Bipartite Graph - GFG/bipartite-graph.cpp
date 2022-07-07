// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isBipartiteDFS(int startIndex,vector<int>adj[], vector<int>&colors){
        
        for(auto nbr: adj[startIndex]){
            if(colors[nbr]==-1){
                // node is not eralier visited i.e coloured
                // colour with opposite colour
                // if parents colour is 1 then assign 0 otherwise 1
                colors[nbr] = colors[startIndex]==0 ? 1: 0;
                bool isbp = isBipartiteDFS(nbr,adj,colors);
                if(!isbp){
                    return false;
                }
            }else{
                // if alredy coloured then
                // check if it has different colour than parent
                // otherwise return false as we cant form a bipertite graph
                if(colors[nbr] == colors[startIndex]){
                    return false;
                }
            }
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> colors(V,-1);
        for(int i=0;i<V;i++){
            if(colors[i]==-1){
                colors[i] = 0;
                if(!isBipartiteDFS(i,adj,colors)){
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