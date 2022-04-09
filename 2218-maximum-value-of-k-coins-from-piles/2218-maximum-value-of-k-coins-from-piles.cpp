class Solution {
public:
    int f(int idx, int k, vector<vector<int>>&piles,vector<vector<int>>&dp){
        if(idx==piles.size() || k==0) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int best = f(idx+1,k,piles,dp);
        // int take = INT_MIN;
        int sum =0;
        for(int i=0;i<min(k,(int)piles[idx].size());i++){
            sum+=piles[idx][i];
            best = max(best,sum+f(idx+1,k-(i+1),piles,dp));
        }
        return dp[idx][k]=best;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>>dp(piles.size()+1, vector<int>(k+1,-1));
        for(int i=0;i<=k;i++){
            dp[piles.size()][i]=0;
        }
        for(int i=0;i<=piles.size();i++) dp[i][0]=0;
        for(int idx=piles.size()-1;idx>=0;idx--){
            for(int amt = 0;amt<=k;amt++){
                int best = dp[idx+1][amt];
                int sum=0;
                for(int j=0;j<min(amt,(int)piles[idx].size());j++){
                    sum+=piles[idx][j];
                    best=max(best,sum+dp[idx+1][amt-(j+1)]);
                }
                dp[idx][amt]=best;
            }
        }
        
        return dp[0][k];
    }
};