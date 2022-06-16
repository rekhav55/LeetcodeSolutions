class Solution {
public:
    bool check(int node, int c, vector<int>&color,vector<vector<int>>&adj){
        for(auto it:adj[node]){
            if(color[it]==c){
                return false;
            }
        }
        return true;
    }
    int f(int n, int i, vector<int>&color,vector<vector<int>>&adj){
        if(i>n) return 1;
        for(int j=1;j<=4;j++){
            if(check(i,j,color,adj)){
                color[i]=j;
                if(f(n,i+1,color,adj)){
                    return 1;
                }
                color[i]=0;
            }
        }
        return 1;
    } 
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<paths.size();i++){
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        
        vector<int>color(n+1,0);
        f(n,1,color,adj);
        color.erase(color.begin());
        return color;
    }
};