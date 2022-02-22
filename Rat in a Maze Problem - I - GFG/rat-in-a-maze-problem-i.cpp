// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(int row,int col,vector<vector<int>>&m,int n,string psf,vector<string>&ans){
        if(row<0 || col<0 || row>=m.size() || col>=m[0].size() || m[row][col]==0) return;
        if(row==n-1 && col==n-1){
            ans.push_back(psf);
            return;
        }
        m[row][col]=0;
        dfs(row-1,col,m,n,psf+"U",ans);
        dfs(row+1,col,m,n,psf+"D",ans);
        dfs(row,col-1,m,n,psf+"L",ans);
        dfs(row,col+1,m,n,psf+"R",ans);
        m[row][col]=1;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        string psf="";
        dfs(0,0,m,n,psf,ans);
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends