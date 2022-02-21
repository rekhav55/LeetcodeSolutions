// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(vector<vector<int>>&grid,int row, int col, int &count){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==0) return ;
        grid[row][col]=0;
        count++;
        dfs(grid,row+1,col,count);
        dfs(grid,row-1,col,count);
        dfs(grid,row,col+1,count);
        dfs(grid,row,col-1,count);
        
        dfs(grid,row+1,col+1,count);
        dfs(grid,row-1,col-1,count);
        dfs(grid,row-1,col+1,count);
        dfs(grid,row+1,col-1,count);
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int count = 0;
                    dfs(grid,i,j,count);
                    ans = max(ans,count);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends