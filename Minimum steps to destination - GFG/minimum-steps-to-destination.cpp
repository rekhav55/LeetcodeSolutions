// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
// int solve(int src, int ctr, int dest){
//         if(abs(src) > (dest)){
//             return INT_MAX;
//         }
//         if(src == dest){
//             return ctr-1;
//         }
//         int l = solve(src+ctr,ctr+1,dest);
//         int r = solve(src-ctr,ctr+1,dest);
//         return min(l,r);
//     }

    int minSteps(int D){
        // code here
        D = abs(D);
       int sum =0, steps=0;
       while(sum<D || (sum-D)%2!=0){
           steps++;
           sum+=steps;
       }
       return steps;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends