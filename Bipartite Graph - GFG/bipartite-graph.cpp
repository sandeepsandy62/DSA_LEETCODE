//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private :
    bool bipartiteBFS(int src , vector<int>adj[] , vector<int>&color){
    queue<int>q;
    color[src] = 1 ;
    q.push(src);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int it : adj[node]){
            if(color[it] == -1){
                color[it] = 1-color[node] ;
                q.push(it);
            }else if(color[it] == color[node]){
                return false;
            }
        }
    }
    
    return true;
}

public:
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    vector<int>color(n,-1);
	    
	    for(int i = 0 ;i < n ;i++){
	        if(color[i]==-1){
	            if(!bipartiteBFS(i,adj,color)){
	              return false;
	            }
	        }
	    }
	
	return true;
}

};

//{ Driver Code Starts.
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
}
// } Driver Code Ends