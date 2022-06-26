class Solution {
public:
    //TLE
    // int f(int leftidx,int rightidx, int k, vector<int>&res,vector<vector<int>>&dp){
    //     if(k==0) return 0;
    //     if(leftidx==res.size() && rightidx<0) return 0;
    //     if(dp[leftidx][rightidx]!=-1) return dp[leftidx][rightidx];
    //     int left=INT_MIN,right=INT_MIN;
    //     if(leftidx<res.size()) left = res[leftidx] + f(leftidx+1,rightidx,k-1,res,dp);
    //     if(rightidx>=0) right = res[rightidx] + f(leftidx,rightidx-1,k-1,res,dp);
    //     return dp[leftidx][rightidx]=max(left,right);
    // }
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum=0;
        for(int i=n-k;i<n;i++){
            sum+=cardPoints[i];
        }
        int ans = sum;
        for(int i=0,j=n-k;i<k;i++,j++){
            sum = sum+cardPoints[i]-cardPoints[j];
            ans = max(sum,ans);
        }
        return ans;
    }
};