class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax=1,currMin=1,res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                currMax=1;
                currMin=1;
            }
            
            int temp = nums[i]*currMax;
            currMax = max({nums[i],currMax*nums[i],currMin*nums[i]});
            currMin = min({temp,currMin*nums[i],nums[i]});
            res=max(res,currMax);
        }
        return res;
    }
};