// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int paths=0;
    void dfs(vector<int>adj[],vector<int>&visited,int src, int des){
        if(src==des){
            paths++;
            return;
        }
        visited[src]=1;
        for(auto it:adj[src]){
            if(visited[it]==0){
                dfs(adj,visited,it,des);
            }
        }
        visited[src]=0;
    }
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        vector<int>visited(V+1,0);
        dfs(adj,visited,source,destination);
        return paths;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends