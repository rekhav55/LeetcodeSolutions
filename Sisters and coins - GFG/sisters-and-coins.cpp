// { Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{
public: 
    int dp[5005][55];
bool recur(int arr[], int idx, int n,int sum, int m){
if(m>sum)return 0;
if(m==sum)return 1;
if(idx>=n)return 0;
if(dp[m][idx]!=-1)return dp[m][idx];
return dp[m][idx]=recur(arr,idx+1,n,sum,m)||recur(arr,idx+1,n,sum-arr[idx],m+arr[idx]);
}
    int sisterCoin(int arr[], int n, int m){
        // Code Here
        int sum=0;
for(int i=0; i<n; i++){
    sum+=arr[i];
    
}
memset(dp,-1,sizeof(dp));
return recur(arr,0,n,sum,m);
}
};


// { Driver Code Starts.

int main()
{
    Solution ob;
	int t;
	cin >> t;
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int a[n];
	    for(int i = 0; i < n; ++i){
	        cin >> a[i];
	    }
	    cout << ob.sisterCoin(a, n, m) << endl;
	    
	}
	return 0;
}  // } Driver Code Ends