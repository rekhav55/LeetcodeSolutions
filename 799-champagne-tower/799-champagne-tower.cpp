class Solution {
public:
    double dp[102][102];
    double champagneTower(int p, int qr, int qg) {
       memset(dp,0,sizeof dp);
        dp[0][0] = p;
        for (int i = 0; i < 100; i++) 
            for (int j = 0; j <= i; j++) {
                if (dp[i][j] >= 1) {
                    double x=(dp[i][j] - 1) / 2.0;
                    dp[i][j] = 1;
                    
                    dp[i + 1][j] += x;
                    dp[i + 1][j + 1] +=x;
                    
                }
            }
        
        return dp[qr][qg];
    }
};