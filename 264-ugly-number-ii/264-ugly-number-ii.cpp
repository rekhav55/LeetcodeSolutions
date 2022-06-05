class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n+1);
        dp[1]=1;
        int p2=1;
        int p3=1;
        int p5=1;
        
        for(int i=2;i<=n;i++){
            int f2=2*dp[p2];
            int f3=3*dp[p3];
            int f5=5*dp[p5];
            
            int mini = min({f2,f3,f5});
            dp[i]=mini;
            if(mini==f2){
                p2++;
            }
            if(mini==f3){
                p3++;
            }
            if(mini==f5){
                p5++;
            }
        }
        
        return dp[n];
    }
};