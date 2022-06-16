class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<bool>&vis, vector<bool>&dfsVis){
        vis[node]=true;
        dfsVis[node]=true;
        for(auto it:graph[node]){
            if(vis[it]==false){
                if(dfs(it,graph,vis,dfsVis)) return true;
            }
            else if(dfsVis[it]==true) return true;
        }
        
        dfsVis[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>vis(n,false);
        vector<bool>dfsVis(n,false);
        vector<int>ans;
        for(int i=0;i<n;i++){
            bool isCycle = dfs(i,graph,vis,dfsVis);
            if(dfsVis[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};