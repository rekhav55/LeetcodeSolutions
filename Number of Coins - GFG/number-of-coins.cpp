// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int find(int idx, int v, int coins[], vector<vector<int>>&dp){
	    if(idx==0){
	        if(v%coins[0]==0) return v/coins[0];
	        return 1e9;
	    }
	    if(dp[idx][v]!=-1) return dp[idx][v];
	    int no_take = find(idx-1,v,coins,dp);
	    int take = INT_MAX;
	    if(coins[idx]<=v) take = 1 + find(idx,v-coins[idx],coins,dp);
	    return dp[idx][v]=min(take,no_take);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M,vector<int>(V+1,-1));
	    int res= find(M-1,V,coins,dp);
	    if(res==1e9) return -1;
	    return res;
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends