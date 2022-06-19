class Solution {
public:
    int f(int idx, vector<int>&res,int amt,vector<vector<int>>&dp){
        if(amt==0) return 0;
        if(idx>=res.size()) return 1e9;
        
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int pick=1e9, no_pick=1e9;
        if(res[idx]<=amt && res[idx]!=0){
            pick = 1+ f(idx,res,amt-res[idx],dp);
        }
        no_pick = f(idx+1,res,amt,dp);
        return dp[idx][amt]=min(pick,no_pick);
    }
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        vector<int>res;
        for(int i=0;i<=num;i++){
            if(i%10==k){
                res.push_back(i);
            }
        }
        vector<vector<int>>dp(res.size()+1,vector<int>(num+1,-1));
        int ans = f(0,res,num,dp);
        return ans>=1e9?-1:ans;
    }
};