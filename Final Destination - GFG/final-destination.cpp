// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int canReach(long long a, long long b, long long x) {
        // code here
        long long int minimum = abs(a)+abs(b);
        if(x<minimum) return 0;
        long long diff = x - minimum;
        if(diff%2==0) return 1;
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,x;
        
        cin>>a>>b>>x;

        Solution ob;
        cout << ob.canReach(a,b,x) << endl;
    }
    return 0;
}  // } Driver Code Ends