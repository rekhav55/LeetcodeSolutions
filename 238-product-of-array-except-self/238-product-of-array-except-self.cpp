class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0;
        int prod=1;
        int n = nums.size();
        vector<int>res(n);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero++;
            if(nums[i]!=0){
                prod*=nums[i];
            }
        }
        
        if(zero>1){
            for(int i=0;i<nums.size();i++){
                res[i]=0;
            }
        }
        if(zero==0){
            for(int i=0;i<nums.size();i++){
                res[i]= prod/nums[i];
            }
        }
        else if(zero==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    res[i]=prod;
                }
                else{
                    res[i]=0;
                }
            }
        }
        return res;
    }
};