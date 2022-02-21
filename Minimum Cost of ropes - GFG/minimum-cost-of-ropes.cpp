// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long int,vector<long long int>,greater<long long int>>q;
        long long ans=0;
        for(long long int i=0;i<n;i++){
            q.push(arr[i]);
        }
        
        while(q.size()>=2){
            long long x = q.top();
            q.pop();
            long long y = q.top();
            q.pop();
            
            ans= ans + x + y;
            long long temp = x+y;
            q.push(temp);
        }
        return ans;
    }
    
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends