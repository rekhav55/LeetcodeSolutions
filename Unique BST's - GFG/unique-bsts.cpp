// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int n) 
    {
        // Your code here
        long long dp[n+1];
        int sum=0;
        dp[0]=1;
        dp[1]=1;
        long long mod = 1000000007;
        for(int i=2;i<=n;i++)
        {
            sum=0;
            for(int j=1;j<=i;j++)
            {
                sum = (sum+(dp[i-j]*dp[j-1])%mod)%mod;
            }
            dp[i] = sum;
        }
        
        
        return dp[n];
    }
};

// { Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	  // } Driver Code Ends