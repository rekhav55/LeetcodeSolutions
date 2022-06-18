class Solution {
public:
    void f(int idx, vector<int>&temp, vector<vector<int>>&ans, vector<int>&nums){
        ans.push_back(temp);
        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            f(i+1,temp,ans,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,temp,ans,nums);
        return ans;
    }
};