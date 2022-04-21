class Solution {
public:
    int f(int r, int c, vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(r<0 || c<0 || c>=matrix[0].size()) return 1e9;
        if(r==matrix.size()-1) return matrix[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        int ans = INT_MAX;
        for(int k=0;k<matrix[0].size();k++){
            if(k!=c){
                ans = min(ans, matrix[r][c]+f(r+1,k,matrix,dp));
            }
        }
        return dp[r][c]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        for(int i=0;i<grid[0].size();i++){
            ans = min(ans,f(0,i,grid,dp));
        }
        return ans;
    }
};