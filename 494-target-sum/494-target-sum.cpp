class Solution {
public:
    int f(int idx,int tar,vector<int>&nums,vector<vector<int>>&dp){
        if(idx==0){
            if(tar==0 && nums[0]==0) return 2;
            if(tar==0 || tar==nums[0]) return 1;
            return 0;
        }
        if(dp[idx][tar]!=-1) return dp[idx][tar];
        int take=0;
        if(nums[idx]<=tar){
            take = f(idx-1,tar-nums[idx],nums,dp);
        }
        int no_take=f(idx-1,tar,nums,dp);
        return dp[idx][tar]= take+no_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int tar = sum - target;
        
        if(tar<0 || tar%2!=0){
            return 0;
        }
        tar/=2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(tar+1,-1));
        return f(nums.size()-1,tar,nums,dp);
    }
};