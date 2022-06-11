class Solution {
public:
    int dp[1001][3];
    int solve(int i,int prev,int flag,vector<int>&nums)
    {
         if(i==nums.size())
            return 0;
        if(dp[i][flag]!=-1){
            return dp[i][flag];
        }
        if(flag==0){
            if(nums[i]>prev){
               return dp[i][flag]=max(1+solve(i+1,nums[i],1,nums),solve(i+1,prev,flag,nums));
            }
            else{
                
               return dp[i][flag]=solve(i+1,prev,flag,nums);
            }
        }
        else if(flag==1){
            if(nums[i]<prev){
               return dp[i][flag]=max(1+solve(i+1,nums[i],0,nums),solve(i+1,prev,flag,nums));
            }
            else{
                
               return dp[i][flag]=solve(i+1,prev,flag,nums);
            }
        }
        else{
           return dp[i][flag]=max({solve(i+1,prev,flag,nums),1+solve(i+1,nums[i],0,nums),1+solve(i+1,nums[i],1,nums)});
        }
        return dp[i][flag];
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return solve(0,0,2,nums);
        
    }
};