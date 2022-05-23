class Solution {
public:
    void dfs(vector<vector<int>>&adj,int node,int &res, vector<int>&informTime,int count){
        for(auto it: adj[node]){
            res = max(res,count+informTime[node]);
            dfs(adj,it,res,informTime,count+informTime[node]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        int res=0;
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        
        dfs(adj,headID,res,informTime,0);
        return res;
        
    }
};