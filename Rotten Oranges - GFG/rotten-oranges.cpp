// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),0));
        queue<pair<int,int>>q;
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) cnt++;
                if(grid[i][j]==2) {
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int k=-1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if(row-1>=0 && visited[row-1][col]==0 && grid[row-1][col]==1){
                    visited[row-1][col]=1;
                    q.push({row-1,col});
                    cnt--;
                }
                if(row+1<grid.size() && visited[row+1][col]==0 && grid[row+1][col]==1){
                    visited[row+1][col]=1;
                    q.push({row+1,col});
                    cnt--;
                }
                if(col+1<grid[0].size() && visited[row][col+1]==0 && grid[row][col+1]==1){
                    visited[row][col+1]=1;
                    q.push({row,col+1});
                    cnt--;
                }
                if(col-1>=0 && visited[row][col-1]==0 && grid[row][col-1]==1){
                    visited[row][col-1]=1;
                    q.push({row,col-1});
                    cnt--;
                }
            }
            k++;
            
        }
        if(cnt!=0) return -1;
        return k;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends