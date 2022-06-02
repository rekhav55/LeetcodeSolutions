class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
            }
        }
        
        if(fresh==0) return 0;
        if(q.size()==0) return -1;
        
        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};
        int n = grid.size();
        int m = grid[0].size();
        int min=-1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                pair<int,int>temp = q.front();
                q.pop();
                int row = temp.first;
                int col = temp.second;
                for(int i=0;i<4;i++){
                    int n_row = row+dr[i];
                    int n_col = col+dc[i];
                    if(n_row>=0 && n_row<n && n_col>=0 && n_col<m){
                        if(grid[n_row][n_col]==1){
                            q.push(make_pair(n_row,n_col));
                            fresh--;
                            grid[n_row][n_col]=2;
                        }
                    }
                }
            }
            min++;
        }
        if(fresh!=0) return -1;
        return min;
    }
};