// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int paths=0;
    void dfs(vector<vector<int>>edges,vector<int>visited, int s, int d){
        if(s==d){
            paths++;
            return;
        }
        visited[s]=1;
        for(auto it:edges[s]){
            if(visited[it]==0){
                dfs(edges,visited,it,d);
            }
        }
        visited[s]=0;
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    vector<vector<int>>graph(n);
	    for(auto it:edges){
	        graph[it[0]].push_back(it[1]);
	    }
	    vector<int>visited(n,0);
	    dfs(graph,visited,s,d);
	    return paths;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends