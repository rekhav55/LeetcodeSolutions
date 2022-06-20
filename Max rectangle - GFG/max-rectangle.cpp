// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int area(vector<int>&temp){
      int n = temp.size();
      vector<int>left(n);
      vector<int>right(n);
      stack<int>st;
      for(int i=0;i<n;i++){
            while(!st.empty() && temp[st.top()]>=temp[i]){
                st.pop();
            }
            if(st.empty()){
              left[i]=0;
            }
            else{
                left[i]=st.top()+1;
            }
            st.push(i);
      }
      
      stack<int>st1;
      for(int i=n-1;i>=0;i--){
          while(!st1.empty() && temp[st1.top()]>=temp[i]){
              st1.pop();
          }
          if(st1.empty()){
              right[i]=n-1;
          }
          else{
              right[i]=st1.top()-1;
          }
          st1.push(i);
      }
      int ans = INT_MIN;
      for(int i=0;i<n;i++){
          if(temp[i]!=0){
              ans = max(ans, (right[i]-left[i]+1)*temp[i]);
          }
      }
      return ans;
  }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int res=0;
        vector<int>temp(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==1){
                    temp[j]+=1;
                }
                else{
                    temp[j]=0;
                }
            }
            int ans = area(temp);
            res = max(res,ans);
        }
        return res;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends