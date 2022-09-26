class Solution {
public:
    int parent[26];
    int rank[26];
    
    int find(int x){
        if(parent[x]==x) return x;
        int temp=find(parent[x]);
        parent[x]=temp;
        return temp;
    }
    
    void unionFind(int x,int y){
        int lx=find(x);
        int ly=find(y);
        if(lx!=ly){
            if(rank[lx]>rank[ly]){
                parent[ly]=lx;
            }
            else if(rank[lx]<rank[ly]){
                parent[lx]=ly;
            }
            else{
                parent[lx]=ly;
                rank[ly]++;
            }
        }
    }
    bool equationsPossible(vector<string>& equations) {
         for(int i=0;i<26;i++){
        parent[i]=i;
        rank[i]=i;
    }
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='='){
                unionFind(equations[i][0]-'a',equations[i][3]-'a');
            }
        }
        
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='!'){
                if(find(equations[i][0]-'a')==find(equations[i][3]-'a')) return false;
            }
        }
        return true;
    }
};