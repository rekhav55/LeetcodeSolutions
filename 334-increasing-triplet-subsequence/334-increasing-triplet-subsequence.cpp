class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return false;
        int second =0, curr_min = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<curr_min){
                curr_min = nums[i];
            }
            else if(nums[i]>curr_min){
                if(second==0){
                    second = i;
                }
                else{
                    if(nums[i]<nums[second]){
                        second =i;
                    }
                    else if(nums[i]>nums[second]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};