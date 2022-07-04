class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int lcnt=0,rcnt=0;
        int n = nums.size();
        int last = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>last) last = nums[i];
            else lcnt++;
        }
        
        last = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(last>nums[i]) last = nums[i];
            else rcnt++;
        }
        
        return min(rcnt,lcnt)<=1;
    }
};