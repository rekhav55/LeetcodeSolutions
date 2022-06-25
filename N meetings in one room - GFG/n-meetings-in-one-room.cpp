// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool myCmp(pair<int, int>& p1, pair<int, int>& p2)
    {
        return p1.second < p2.second;
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        pair<int, int> arr[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = {start[i], end[i]};
        }
        
        sort(arr, arr+n, myCmp);
        
        int res = 1, prev = 0;
        
        for(int i = 1; i < n; i++)
        {
            if(arr[i].first > arr[prev].second)
            {
                res++;
                prev = i;
            }
        }
    
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends