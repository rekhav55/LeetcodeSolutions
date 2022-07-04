class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=nums[0];
        int start=0,end=0,n=nums.size();
        int ans = INT_MAX;
        while(start<n && end<n){
            if(sum<target){
                end++;
                if(end<n){
                    sum+=nums[end];
                }
            }
            else{
                while(sum>=target && start<n){
                    ans = min(ans, end-start+1);
                    sum-=nums[start];
                    start++;
                }
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};