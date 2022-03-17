// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    bool isValid(int x, int y, int rows, int cols){
        if(x < 0 || x >= rows || y < 0 || y>= cols){
            return false;
        }
        return true;
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int rows = grid.size();
	    int cols = grid[0].size();
	    queue<pair<int, int>> q;
	    vector<vector<bool>> visited;
	    vector<vector<int>> ans;
	    for(int i = 0; i < rows; i++){
	        vector<bool> v (cols, false);
	        vector<int> a (cols, INT_MAX);
	        visited.push_back(v);
	        ans.push_back(a);
	    }
	    for(int i = 0; i < rows; i++){
	        for(int j = 0; j < cols; j++){
	            if(grid[i][j] == 1){
	                visited[i][j] = true;
	                ans[i][j] = 0;
	                q.push({i, j});
	            }
	        }
	    }
	    int dx[4] = {0, 1, 0, -1};
	    int dy[4] = {1, 0, -1, 0};
	    while(q.empty() == false){
	        int x = q.front().first;
	        int y = q.front().second;
	        q.pop();
	        int currDist = ans[x][y];
	        for(int i = 0; i < 4; i++){
	            int xdx = x + dx[i];
	            int ydy = y + dy[i];
	            if(isValid(xdx, ydy, rows, cols)){
	            if(visited[xdx][ydy] == false){
	                visited[xdx][ydy] = true;
	                q.push({xdx, ydy});
	                ans[xdx][ydy] = currDist + 1;
	            }
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends