// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int dx[4]={0,0,1,-1};
    int dy[4]={-1,1,0,0};

    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        //create min heap
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > st;  
        st.push({grid[0][0],{0,0}});
        dp[0][0]=grid[0][0];
        while(!st.empty())
        {
            
            auto ele=st.top();
            st.pop();
            int dis=ele.first;
            int x=ele.second.first;
            int y=ele.second.second;
            
            for(int i=0;i<4;i++)
            {
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0 && newx<n && newy>=0 && newy<n)
                {
                    if(dp[newx][newy]>dis+grid[newx][newy])
                    {
                        dp[newx][newy]=dis+grid[newx][newy];
                        st.push({dp[newx][newy],{newx,newy}});
                    }
                }
            }
        }
        
        return dp[n-1][n-1];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends