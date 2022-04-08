// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
        bool f(vector<int>&nums,int sum,int i, int m, vector<vector<bool>>&dp){
            if(sum%m==0 && sum!=0) return true;
            if(i<0) return false;
            if(dp[i][sum]) return dp[i][sum];
            return dp[i][sum]=f(nums,sum,i-1,m,dp)||f(nums,sum-nums[i],i-1,m,dp);
        }
		int DivisibleByM(vector<int>nums, int m){
		    // Code here
		    int sum =0;
		    int n = nums.size();
		    for(int i = 0; i < n; i++)
	    {
	        sum += nums[i];
	    }
	    
	    vector<vector<bool>> dp(n + 1, vector<bool> (sum + 1, false));
	    return f(nums,sum,n-1,m,dp);
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans  = ob.DivisibleByM(nums, m);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends