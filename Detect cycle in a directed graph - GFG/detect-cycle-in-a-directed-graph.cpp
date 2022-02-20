// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checkCycle(int node, vector<int>&visited, vector<int>&dfsVisited, vector<int>adj[]){
        visited[node]=1;
        dfsVisited[node]=1;
        for(auto it:adj[node]){
            if(visited[it]==0){
                if(checkCycle(it,visited,dfsVisited,adj)) return true;
            }
            else if(visited[it]==1 && dfsVisited[it]==1) return true;
        }
        
        dfsVisited[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>visited(V,0);
        vector<int>dfsVisited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(checkCycle(i,visited,dfsVisited,adj)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends