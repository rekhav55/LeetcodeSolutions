class Solution {
public:
    int robber(vector<int>&nums, int i,vector<int>&dp){
        if(i==0) return nums[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+robber(nums,i-2,dp);
        int nopick=robber(nums,i-1,dp);
        return dp[i]=max(pick,nopick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int>dp(nums.size(),-1);
        return robber(nums,nums.size()-1,dp);
    }
};