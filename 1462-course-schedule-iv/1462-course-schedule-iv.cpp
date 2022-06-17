class Solution {
public:
    void dfs(int node,stack<int>&s, vector<vector<int>>&adj, vector<int>&visited){
        visited[node]=1;
        for(auto it:adj[node]){
            if(visited[it]==0){
                dfs(it,s,adj,visited);
            }
        }
        s.push(node);
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
//         vector<bool>ans(queries.size(),false);
//         if(prerequisites.size()==0) return ans;
//         vector<vector<int>>adj(numCourses);
//         for(int i=0;i<prerequisites.size();i++){
//             adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
//         }
        
//         stack<int>s;
//         vector<int>visited(numCourses,0);
//         for(int i=0;i<adj.size();i++){
//             if(visited[i]==0) dfs(i,s,adj,visited);
//         }
        
//         vector<int>rank(numCourses,-1);
//         int cnt=0;
//         while(!s.empty()){
//             int x = s.top();
//             s.pop();
//             cout<<x<<" ";
//             rank[x]=cnt;
//             cnt++;
//         }
//         for(int i=0;i<queries.size();i++){
//             int x = queries[i][0];
//             int y = queries[i][1];
//             if(rank[x]<rank[y]){
//                 ans[i]=true;
//             }
//             else{
//                 ans[i]=false;
//             }
//         }
//         return ans;
        vector<vector<int>>adj(numCourses,vector<int>(numCourses,1e9));
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]][prerequisites[i][1]]=1;
        }
        for(int k=0;k<numCourses;k++){
            for(int i=0;i<numCourses;i++){
                for(int j=0;j<numCourses;j++){
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            if(adj[queries[i][0]][queries[i][1]]!=1e9){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};