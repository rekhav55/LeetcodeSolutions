class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi = -1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi = nums[i];
            }
            else{
                maxi++;
                cnt+=(maxi-nums[i]);
            }
        }
        return cnt;
    }
};
