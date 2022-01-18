class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix[0].size();
        int n=matrix.size();
        int cnt=0;
        int dp[n][m];
        // for(int i=0;i<=n;i++)
        //     for(int j=0;j<=m;j++)
        //         dp[i][j]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0){
                    dp[i][j]=0;
                }
                else{
                    if(i==0){
                        dp[i][j]=1;
                        cnt+=dp[i][j];
                    }
                    else if(j==0){
                        dp[i][j]=1;
                        cnt+=dp[i][j];
                    }
                    else{
                        dp[i][j]= min(dp[i-1][j-1], min(dp[i][j-1],dp[i-1][j]))+1;
                        cnt+=dp[i][j];
                    }
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cnt+=dp[i][j];
        //     }
        // }
        return cnt;
    }
    
};