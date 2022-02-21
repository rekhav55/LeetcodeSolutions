// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
// 	void findTopoSort(vector<int>adj[],stack<int>&st,int node,vector<int>&vis){
// 	    vis[node]=1;
// 	    for(auto it:adj[node]){
// 	        if(vis[it]==0) findTopoSort(adj,st,it,vis);
// 	    }
// 	    st.push(node);
// 	}
// 	void dfs(int node, vector<int>transpose[],vector<int>&vis){
// 	    vis[node]=1;
// 	    for(auto it:transpose[node]){
// 	        dfs(it,transpose,vis);
// 	    }
// 	}
void dfs(int V, vector<int> adj[], stack<int> &st, vector<bool> &visited, int i){
	    visited[i] = true;
	    for(auto &v : adj[i]){
	        if(visited[v] == false){
	            dfs(V, adj, st, visited, v);
	        }
	    }
	    st.push(i);
	}
	void dfs2(int V, vector<int> adj[], vector<bool> &visited, int i){
	    visited[i] = true;
	    for(auto &v : adj[i]){
	        if(visited[v] == false){
	            dfs2(V, adj,visited, v);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> st;
        vector<bool> visited (V, false);
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                dfs(V, adj, st, visited, i);
            }
        }
        vector<int> transpose[V];
        for(int i = 0;i < V; i++){
            visited[i] = false;
            for(auto &e : adj[i]){
                transpose[e].push_back(i);
            }
        }
        int cnt=0;
        while(!st.empty()){
            int curr = st.top();
            if(visited[curr] == false){
                dfs2(V, transpose, visited, curr);
                cnt++;
            }
            st.pop();
        }
        return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends