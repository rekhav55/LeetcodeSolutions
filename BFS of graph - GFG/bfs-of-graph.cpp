// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        if(V==0) return {};
        queue<int>q;
        q.push(0);
        vector<int>visited(V+1,0);
        visited[0]=1;
        vector<int>result;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                result.push_back(q.front());
                int x = q.front();
                q.pop();
                for(auto it: adj[x]){
                    if(visited[it]==0){
                        q.push(it);
                        visited[it]=1;
                    }
                }
            }
        }
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends