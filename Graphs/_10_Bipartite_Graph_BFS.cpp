//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
private:

    bool check(int start, vector<int>adj[],int color[]){
        queue<int> q;
	    q.push(start);
	    color[start]=-1;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        for(auto it: adj[node]){
	            //If the adjacent node are not yet coloured
	            //Give oposite color to the node
	            if(color[it]==-1){
	                color[it]= !color[node];
	                q.push(it);
	            }
	            
	            else if(color[it]==color[node]){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i=0; i<V;i++){
	        color[i]=-1;
	    }
	    
	    for(int i=0; i<V; i++){
	        if(color[i]==-1){
	            if(check(i, adj, color)==false){
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