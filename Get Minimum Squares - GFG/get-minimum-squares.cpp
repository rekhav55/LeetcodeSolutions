// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int f(int n, vector<int>&dp){
	    if(sqrt(n)-floor(sqrt(n))==0) return 1;
	    if(n<=3) return n;
	    if(dp[n]!=-1) return dp[n];
	    int res = n;
	    for(int x = 1; x<=n; x++){
	        int temp = x*x;
	        if(temp>n) break;
	        res = min(res, 1 + MinSquares(n-temp));
	    }
	    return dp[n]=res;
	}
	int MinSquares(int n)
	{
	    // Code here
	    vector<int>dp(n+1,-1);
	    if(n<=3) return n;
	    dp[0]=0;
	    dp[1]=1;
	    dp[2]=2;
	    dp[3]=3;
	    for(int i=4;i<=n;i++){
	        dp[i]=i;
	        for(int x =1; x<=ceil(sqrt(i));x++){
	            int temp = x*x;
	            if(temp>i) break;
	            dp[i] = min(dp[i], 1+dp[i-temp]);
	        }
	    }
	    return dp[n];
	    return f(n,dp);
	    
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends