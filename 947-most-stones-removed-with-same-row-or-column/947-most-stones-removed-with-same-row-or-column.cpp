class Solution {
public:
        void dfs(int node,vector<int> adj[],vector<bool> &vis){
        
        vis[node] = true;
        for(auto &i : adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }

    int removeStones(vector<vector<int>>& s) {
        int n = s.size();
        
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s[i][0] == s[j][0] || s[i][1] == s[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;
            }
        }
        return n-count;
    }

};
