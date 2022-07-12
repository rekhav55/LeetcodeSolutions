class Solution {
int dp[(1<<16)];
    bool solve(vector<int>& nums){
        
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum % 4 != 0){
            return false;
        }
        sum /= 4;
        
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        for(int msk=0 ; msk<(1<<n); msk++){
            
            if(dp[msk] == -1) continue;
            
            for(int i=0;i< n;i++){
                
                if(!(msk&(1<<i)) and dp[msk]+nums[i] <= sum){
                    dp[msk | (1<<i)] = (dp[msk]+nums[i])%sum;
                }
            }
        }
        if(dp[(1<<nums.size())-1] == 0){
            return true;
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        return solve(nums);
    }
};