class Solution {
public:
    int robber(vector<int>&nums,int i, int last, vector<int>&dp){
        if(i==last) return nums[last];
        if(i<last) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+robber(nums,i-2,last,dp);
        int nopick=robber(nums,i-1,last,dp);
        return dp[i]=max(pick,nopick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int>dp(nums.size()+1,-1);
        vector<int>dp1(nums.size()+1,-1);
        return max(robber(nums,nums.size()-1,1,dp),robber(nums,nums.size()-2,0,dp1));
    }
};