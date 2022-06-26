// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int weeks = S/7;
        int days_she_can_buy = S-weeks;
        int total_food_needed = S*M;
        
        int min_days = (total_food_needed)/N;
        if(total_food_needed%N >0) min_days++;
        
        if(min_days>days_she_can_buy) return -1;
        return min_days;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}  // } Driver Code Ends