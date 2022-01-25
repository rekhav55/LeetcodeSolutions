class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int dp[matrix.size()][matrix[0].size()];
        int count = INT_MIN;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    if(i==0){
                        dp[i][j]=1;
                        count=max(count,dp[i][j]);
                    }
                    else if(j==0){
                        dp[i][j]=1;
                        count=max(count,dp[i][j]);
                    }
                    else{
                        dp[i][j]=min(dp[i][j-1], min(dp[i-1][j-1],dp[i-1][j]))+1;
                        count=max(count,dp[i][j]);
                    }
                }
                else{
                    dp[i][j]=0;
                    count=max(count,dp[i][j]);
                }
            }
        }
        return count*count;
    }
};