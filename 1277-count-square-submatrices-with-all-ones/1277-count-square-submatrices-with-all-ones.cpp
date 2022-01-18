class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix[0].size();
        int n=matrix.size();
        int cnt=0;
        // int dp[n][m];
        // for(int i=0;i<=n;i++)
        //     for(int j=0;j<=m;j++)
        //         dp[i][j]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1){
                    if(i==0){
                        cnt+=matrix[i][j];
                    }
                    else if(j==0){
                        cnt+=matrix[i][j];
                    }
                    else{
                        matrix[i][j]= min(matrix[i-1][j-1], min(matrix[i][j-1],matrix[i-1][j]))+1;
                        cnt+=matrix[i][j];
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