class Solution {
public:
    int f(int i, int j, vector<vector<int>>&tri,vector<vector<int>>&dp){
        if(i==tri.size()-1){
            return tri[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int down=INT_MAX,dig=INT_MAX;
        down = tri[i][j]+f(i+1,j,tri,dp);
        dig=tri[i][j]+f(i+1,j+1,tri,dp);
        return dp[i][j]=min(down,dig);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(0,0,triangle,dp);
    }
};