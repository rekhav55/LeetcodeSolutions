class Solution {
public:
    int ans = 1;
    int find(int x,vector<int> &par){
        if(x==par[x]){
            return x;
        }
        int t=find(par[x],par);
        par[x]=t;
        return t;
    }
    void uni(int i,int j,vector<int> &par,vector<int> &rank){
        int lx=find(i,par);
        int ly=find(j,par);
        if(lx!=ly){
            if(rank[lx]>rank[ly]){
                par[ly]=lx;
            }else if(rank[lx]<rank[ly]){
                par[lx]=ly;
            }else{
                par[lx]=ly;
                rank[ly]++;
            }
        }
        else ans++;
    }
    int regionsBySlashes(vector<string>& grid) {
        int dots = grid.size()+1;
        vector<int> par(dots*dots);
        vector<int> rank(dots*dots,1);
        for(int i=0;i<par.size();i++){
            par[i]=i;
        }
        for(int i=0;i<grid.size()+1;i++){
            for(int j=0;j<grid[0].size()+1;j++){
                if(i==0||j==0||i==grid.size()||j==grid[0].size()){
                    int cellno=i*(dots)+j;
                    if(cellno!=0){
                        uni(0,cellno,par,rank);
                    }
                }
            }
        }
      for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='/'){
                    int x=i*(dots)+j+1;
                    int y=(i+1)*(dots)+j;
                    uni(x,y,par,rank);
                }else if(grid[i][j]=='\\'){
                         int x=i*(dots)+j;
                    int y=(i+1)*(dots)+j+1;
                    uni(x,y,par,rank);
                }
            }
      }
      return ans;
        
    }
    
};