class TreeAncestor {
public:
//     map<int,int>mp;
//     map<int,set<pair<int,int>>>st;
//     TreeAncestor(int n, vector<int>& parent) {
//         for(int i=0;i<n;i++){
//             mp[i]=parent[i];
//         }
//     }
//     int f(int node,int x, int k, int lvl){
//         if(lvl==k){
//             st[x].insert({k,mp[node]});
//             return mp[node];
//         }
//         if(mp[node]==-1){
//             for(int i=lvl;i<=k;i++){
//                 st[x].insert({i,-1});
//             }
//             return -1;
//         }
//         st[x].insert({lvl,mp[node]});
//         return f(mp[node],x,k,lvl+1);
//     }
//     int getKthAncestor(int node, int k) {
//         if(st.find(node)==st.end()) return f(node,node,k,1);
        
//             set<pair<int,int>>temp = st[node];
//             auto it = temp.rbegin();
//             if(it->first<k){
//                 if(it->second==-1) return -1;
//                 else return f(it->second,node,k,it->first+1);
//             }
//             else if(it->first==k){
//                 return it->second;
//             }
//             else{
//                 for(auto p:temp){
//                     if(p.first==k){
//                         return p.second;
//                     }
//                 }
//             }
//         return -1;
        
//     }
    vector<vector<int>>look;
    TreeAncestor(int n, vector<int>& parent) {
        int si = floor(log2(n))+1;
        
        look.resize(n, vector<int>(si));
        for(int i=0;i<n;i++){
            look[i][0] = parent[i];
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<si;j++){
                if(look[i][j-1]!=-1){
                    look[i][j] = look[look[i][j-1]][j-1];
                }else{
                    look[i][j]=-1;
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int cur = node;
        for(int b=0;b<32&&cur!=-1;b++){
            if(k&(1<<b)){
                cur = look[cur][b];
            }
        }
        return cur;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */