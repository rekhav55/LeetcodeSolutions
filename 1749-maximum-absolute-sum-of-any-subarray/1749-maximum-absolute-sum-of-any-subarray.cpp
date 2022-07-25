class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int current_sum=0;
int min_val=INT_MAX;
int max_val=INT_MIN;

    for(int i=0;i<nums.size();i++){
        current_sum+=nums[i];
        if(current_sum<0)
            current_sum=0;
        max_val=max(current_sum,max_val);
    }
    
    current_sum=0;
    
    for(int i=0;i<nums.size();i++){
        current_sum+=nums[i];
        if(current_sum>0)
            current_sum=0;
        min_val=min(current_sum,min_val);
    
    }
   return max(max_val,abs(min_val));
    }
};