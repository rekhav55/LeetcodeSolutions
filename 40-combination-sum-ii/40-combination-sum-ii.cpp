class Solution {
public:
    vector<vector<int>>res;
    void helper(int idx,int tar,vector<int>&nums, vector<int>&ans){
        if(tar==0) {
            res.push_back(ans);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i]>tar) break;
            ans.push_back(nums[i]);
            helper(i+1,tar-nums[i],nums,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ans;
        helper(0,target,candidates,ans);
        return res;
    }
};