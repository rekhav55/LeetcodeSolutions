class Solution {
public:
    bool f(int idx, int tar, vector<int>&nums,vector<vector<int>>&dp){
        if(tar==0){
            return true;
        }
        if(idx==nums.size()) return false;
        if(dp[idx][tar]!=-1) return dp[idx][tar];
        bool take = false, no_take=false;
        if(nums[idx]<=tar){
            take = f(idx+1,tar-nums[idx],nums,dp);
            no_take = f(idx+1,tar,nums,dp);
        }
        else{
            no_take = f(idx+1,tar,nums,dp);
        }
        return dp[idx][tar]=take || no_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(nums.size()+1,vector<int>((sum/2) +1,-1));
        if(sum%2==1) return false;
        return f(0,sum/2,nums,dp);
    }
};