// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool com(const pair<int,int>&a,const pair<int,int>&b){
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            temp.push_back(make_pair(start[i],end[i]));
        }
        sort(temp.begin(),temp.end(),com);
        int ans=1;
        int time_limit = temp[0].second;
        for(int i=1;i<n;i++){
            // pair<int,int>s = temp[i-1];
            if(temp[i].first>time_limit){
                ans++;
                time_limit=temp[i].second;
            }
        }
        return ans;
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