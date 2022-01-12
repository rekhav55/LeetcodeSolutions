class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int ans=0;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            int sum = nums[i];
            res.push_back(sum);
            for(int j=i+1;j<nums.size();j++){
                sum+=nums[j];
                res.push_back(sum);
            }
        }
        sort(res.begin(),res.end());
        for(int i=left-1;i<=right-1;i++){
            ans+=res[i];
            ans= ans%(1000000000+7);
        }
        return ans;
    }
};