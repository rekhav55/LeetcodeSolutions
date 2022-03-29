// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int find(int idx, int arr[],vector<int>&dp){
        if(idx<0) return 0;
        if(idx==0) return arr[0];
        if(dp[idx]!=-1) return dp[idx];
        int no_take = find(idx-1,arr,dp);
        int take = arr[idx]+find(idx-2,arr,dp);
        return dp[idx]=max(no_take,take);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>dp(n,-1);
        return find(n-1,arr,dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends