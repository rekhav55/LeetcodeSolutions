class Solution {
public:
    bool dfs(int node, vector<vector<int>>&adj, vector<int>&color){
        if(color[node]==-1){
            color[node]=1;
        }
        
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                if(!dfs(it,adj,color)) return false;
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!dfs(i,adj,color)) return false;
            }
        }
        return true;
    }
};