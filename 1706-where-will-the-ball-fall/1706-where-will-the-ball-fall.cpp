class Solution {
public:
    int a,n,m;
    bool check(vector<vector<int>>& grid,int row, int col)
    {
        if(row==n)
        {
            a = col;
            return true;
        }
            
        
        if((col==0 && grid[row][col]==-1) || (col==m-1 && grid[row][col]==1))
            return false;
        else if(grid[row][col]==1)
        {
            if(grid[row][col+1]==1)
                return check(grid,row+1,col+1);
            else
                return false;
        }
        else if(grid[row][col]==-1)
        {
            if(grid[row][col-1]==-1)
                return check(grid,row+1,col-1);
            else
                return false;
        }
        
        return true;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(m==1)
            return {-1};
        
        vector<int> ans;
        for(int i=0;i<m;i++)
        {
            if(check(grid,0,i))
                ans.push_back(a);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};

// grid[i][j]==1 and grid[i][j+1]==1 f(i+1,j+1)
// grid[i][j]==-1 and grid[i][j-1]==-1 f(i+1,j-1)
// grid[i][j]==1 and grid[i][j+1]==-1 fucked
// grid[i][j]==-1 and grid[i][j-1]==1 fucked
