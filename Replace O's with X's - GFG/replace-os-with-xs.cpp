// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
void change(int x,int y, vector<vector<char>>& mat)
   {
    //   if(x<0 || y<0 || x>=mat.size() || y>=mat[0].size() || mat[x][y]=='X') return ;
    //   mat[x][y]='*';
    //   change(x,y+1,mat);
    //   change(x,y-1,mat);
    //   change(x+1,y,mat);
    //   change(x-1,y,mat);
      mat[x][y] = '*';
      int dx[] = {0,0,1,-1};
      int dy[] = {1,-1,0,0};
      for(int i = 0; i < 4; i++)
      {
          int cx = x + dx[i];
          int cy = y + dy[i];
          if(cx >= 0 && cx < mat.size() && cy >= 0 && cy < mat[0].size() && mat[cx][cy] == 'O')
              change(cx,cy,mat);
      }
   }
   vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
   {
       // code here
       for(int i = 0; i < n; i++)
       {
           for(int j = 0; j < m; j++)
           {
               if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
                   if(mat[i][j] == 'O')
                       change(i,j,mat);
           }
       }
       for(int i = 0; i < n; i++)
       {
           for(int j = 0; j < m; j++)
           {
               if(mat[i][j] == 'O')
                   mat[i][j] = 'X';
           }
       }
       for(int i = 0; i < n; i++)
       {
           for(int j = 0; j < m; j++)
           {
               if(mat[i][j] == '*')
                   mat[i][j] = 'O';
           }
       }
       return mat;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends