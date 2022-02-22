class Solution {
public:
    // void dfs(vector<vector<int>>&image,int sr, int sc, int newColor, int oldColor){
    //     if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=oldColor || image[sr][sc]==newColor) return;
    //     image[sr][sc]=newColor;
    //     dfs(image,sr+1,sc,newColor,oldColor);
    //     dfs(image,sr-1,sc,newColor,oldColor);
    //     dfs(image,sr,sc+1,newColor,oldColor);
    //     dfs(image,sr,sc-1,newColor,oldColor);
    // }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int color = image[sr][sc];
        image[sr][sc]=newColor;
        int m[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                pair<int,int>temp = q.front();
                q.pop();
                int r = temp.first;
                int c = temp.second;
                for(int j=0;j<4;j++){
                    int rn = r + m[j][0];
                    int cn = c + m[j][1];
                    if(rn>=0 && cn>=0 && rn<image.size() && cn<image[0].size() && image[rn][cn]==color && image[rn][cn]!=newColor){
                        image[rn][cn]=newColor;
                        q.push({rn,cn});
                    }
                }
            }
        }
        return image;
    }
};