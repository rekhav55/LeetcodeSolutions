class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0;
        int prod=1;
        int n = nums.size();
        vector<int>res(n);
        vector<int>left(n);
        vector<int>right(n);
        for(int i=0;i<n;i++){
            if(i==0) left[0]=1;
            else{
                left[i]= left[i-1]*nums[i-1];
            }
        }
        right[n-1]=1;
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]*nums[i+1];
        }
        
        for(int i=0;i<n;i++){
            res[i]=left[i]*right[i];
        }
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0) zero++;
//             if(nums[i]!=0){
//                 prod*=nums[i];
//             }
//         }
        
//         if(zero>1){
//             for(int i=0;i<nums.size();i++){
//                 res[i]=0;
//             }
//         }
//         if(zero==0){
//             for(int i=0;i<nums.size();i++){
//                 res[i]= prod/nums[i];
//             }
//         }
//         else if(zero==1){
//             for(int i=0;i<nums.size();i++){
//                 if(nums[i]==0){
//                     res[i]=prod;
//                 }
//                 else{
//                     res[i]=0;
//                 }
//             }
//         }
        return res;
    }
};