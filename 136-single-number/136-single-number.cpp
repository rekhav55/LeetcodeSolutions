class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cons =0;
        for(int i=0;i<nums.size();i++){
            cons=cons^nums[i];
        }
        return cons;
    }
};