class Solution {
public:
    map<pair<pair<int,int>,pair<int,int>>, int> m;
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        
       
        int ans =  rec(0,0,0,0,row,col,grid) ;
        return ans < 0  ? 0 : ans;
    }
    
    int rec(int i1, int c1, int i2, int c2, int row, int col , vector<vector<int>>& grid)
    {
        if(i1 <0 or i1 >= row or c1 <0 or c1 >=col or i2 <0 or i2>=row or c2 <0 or c2 >=col or grid[i1][c1] == -1 or grid[i2][c2] == -1)
        {
            return -1000000 ;
        }
        
        // both of them reach the end
        if(i1 == row-1 and c1 == col-1 )
        {
            return grid[i1][c1];
        }
        
        auto p =make_pair(make_pair(i1,c1),make_pair(i2,c2));
        if(m.find(p) != m.end())
            return m[p];
            
        
        int cherries = 0;
        
        // if both of them are in the same cell
        if(i1 == i2 and c1 == c2)
            cherries +=grid[i1][c1];
        else
            cherries += grid[i1][c1] + grid[i2][c2];
        
        
        //  make a recursive call to all the possible directions
        int f1 = rec(i1+1, c1, i2+1,c2, row,col,grid);
        int f2 = rec(i1, c1+1, i2,c2+1, row,col,grid);
        int f3 = rec(i1+1, c1, i2,c2+1, row,col,grid);
        int f4 = rec(i1, c1+1, i2+1,c2, row,col,grid);
        
        cherries +=  max(max(f1,f2), max(f3,f4));
        
        auto t = make_pair(make_pair(i1,c1),make_pair(i2,c2));
        m[t] = cherries;
        return cherries;
    }
};