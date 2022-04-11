class Solution {
public:
    int sum(int start, int end, vector<int>&arr){
        int maxi=INT_MIN;
        for(int i=start;i<=end;i++){
            maxi=max(arr[i],maxi);
        }
        
        return maxi*(end-start+1);
    }
    int f(int start, int end, vector<int>&arr, int k,vector<int>&dp){
        if(start>end) return 0;
        if(dp[start]!=-1) return dp[start];
        int best=INT_MIN;
        for(int i=start;i<arr.size();i++){
            if(i-start>=k) break;
            int x = sum(start,i,arr) + f(i+1,end,arr,k,dp);
            best=max(best,x);
        }
        return dp[start]=best;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       int n = arr.size()-1;
        vector<int>dp(n+2,-1);
        return f(0,n,arr,k,dp);
    }
};