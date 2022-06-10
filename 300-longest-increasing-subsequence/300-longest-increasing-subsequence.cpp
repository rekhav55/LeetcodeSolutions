class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp;
        dp.push_back(nums[0]);
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[j]<nums[i] && dp[i]<dp[j]+1){
        //             dp[i]=dp[j]+1;
        //         }
        //         maxi = max(maxi,dp[i]);
        //     }
        // }
        // return maxi;
        for(int i=1;i<n;i++){
            if(nums[i]>dp.back()){
                dp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                dp[idx]=nums[i];
            }
        }
        return dp.size();
    }
};