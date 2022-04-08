// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


 // } Driver Code Ends
class Solution
{
    public:
    int bridges(string &str1, string &str2 , int i , int j){
        vector<vector<int>>dp(i+1,vector<int>(j+1,0));
        for(int idx=1;idx<=i;idx++){
            for(int jdx=1;jdx<=j;jdx++){
                if(str1[idx-1]==str2[jdx-1]){
                    dp[idx][jdx]=1+dp[idx-1][jdx-1];
                }
                else dp[idx][jdx]=max(dp[idx-1][jdx],dp[idx][jdx-1]);
            }
        }
        return dp[i][j];
    }
    int build_bridges(string str1, string str2)
    {
        // code here
        int n = str1.size();
        int m = str2.size();
        return bridges(str1,str2,n,m);
    }
};

// { Driver Code Starts.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    } 
    return 0;
} 
  // } Driver Code Ends