// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	#define mod 1000000007
	int helper(int n,int arr[], int sum,vector<vector<int>>&dp){
	    
   
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
         int dp[n+1][sum+1];
       //initialization
           dp[0][0]=1;
           for(int j=1;j<sum+1;j++)
           {
                   dp[0][j]=0;
               
           }
            for(int i=1;i<n+1;i++) 
       {
           for(int j=0;j<sum+1;j++)
           {
               if(arr[i-1]<=j)
               {
                   dp[i][j]=dp[i-1][j]%1000000007 + dp[i-1][j-arr[i-1]]%1000000007;
               }
               else{
                  dp[i][j]=dp[i-1][j]%1000000007; 
               }
           }
       }
       
       return dp[n][sum]%1000000007;
       
       
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends