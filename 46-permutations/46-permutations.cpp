class Solution {
public:
    void f(int idx, vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans){
        if(idx>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            f(idx+1,nums,temp,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,nums,temp,ans);
        return ans;
    }
};