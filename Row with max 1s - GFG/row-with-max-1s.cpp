// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    int f(int left, int right, vector<int>mat){
        int ans=-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(mat[mid]==1){
                ans = mid;
                right=mid-1;
            }
            else if(mat[mid]==0){
                left=mid+1;
            }
        }
        if(ans==-1) return 0;
        return mat.size()-ans;
    }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int ans =0, res=0,idx=-1;
	    for(int i=0;i<arr.size();i++){
	        int ans = f(0,m-1,arr[i]);
	        if(ans!=0 && ans>res){
	            idx = i;
	            res=ans;
	        }
	    }
	    return idx;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends