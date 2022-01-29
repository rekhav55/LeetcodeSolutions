class Solution {
public:
    class unionFind{
        public:
        unionFind(int n): parent(n), rank(n){
            for(int i=0;i<n;i++){
                parent[i]=i;
                rank[i]=1;
            }
        }
        
        int find(int x){
            if(x==parent[x]) return x;
            return find(parent[x]);
        }
        
        bool unionF(int x, int y){
            int parentX = find(x);
            int parentY = find(y);
            if(parentX==parentY) return true;
            else{
                if(rank[parentX]>rank[parentY]){
                    parent[parentY]=parentX;
                }
                else if(rank[parentX]<rank[parentY]){
                    parent[parentX]=parentY;
                }
                else{
                    parent[parentY]=parentX;
                    rank[parentX]++;
                }
                return false;
            }
        }
        
        private:
        vector<int>parent;
        vector<int>rank;
    };
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unionFind uf(n);
        for(auto it:edges){
            uf.unionF(it[0],it[1]);
        }
        return uf.unionF(source,destination);
    }
};