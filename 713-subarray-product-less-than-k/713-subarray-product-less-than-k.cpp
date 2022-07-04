class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long int prod=nums[0];
        int start=0,end=0,n=nums.size(),count=0;
        while(start<n && end<n){
            if(prod<k){
                end++;
                if(end>=start){
                    count+= (end-start);
                }
                if(end<n){
                    prod*=nums[end];
                }
            }
            else{
                prod/=nums[start];
                start++;
            }
        }
        
        return count;
    }
};