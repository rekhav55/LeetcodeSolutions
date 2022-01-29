class Solution {
public:
    int find(int x, vector<int>&par){
        if(x==par[x]) return x;
        return par[x]=find(par[x],par);
    }
    bool uni(int x, int y, vector<int>&par, vector<int>&rank){
        int lx = find(x,par);
        int ly = find(y,par);
        if(lx!=ly){
            if(rank[lx]>rank[ly]){
                par[ly]=lx;
            }
            else if(rank[lx]<rank[ly]){
                par[lx]=ly;
            }
            else{
                par[lx]=ly;
                ly++;
            }
            return false;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>parent(edges.size()+1);
        vector<int>rank(edges.size()+1, 1);
        vector<int>ans;
        for(int i=0;i<edges.size();i++){
            parent[i]=i;
        }
        for(auto it:edges){
            bool flag = uni(it[0],it[1],parent,rank);
            if(flag==true){
                ans.push_back(it[0]);
                ans.push_back(it[1]);
                break;
            }
        }
        return ans;
    }
};