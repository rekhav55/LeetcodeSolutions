class Solution {
public:
    int countVowelStrings(int n) {
        if(n==1) return 5;
        int dp[n+1][6];
        int sum=0;
        for(int i=0;i<6;i++) dp[0][i]=0;
        for(int i=0;i<5;i++) dp[1][i]=1;
        dp[1][5]=5;
        for(int i=2;i<=n;i++){
            for(int j=0;j<5;j++){
                if(j==0){
                    dp[i][j]=dp[i-1][5];
                    sum+=dp[i][j];
                }
                else{
                    dp[i][j]=dp[i][j-1]-dp[i-1][j-1];
                    sum+=dp[i][j];
                }
            }
            dp[i][5]=sum;
            sum=0;
        }
        return dp[n][5];
    }
};