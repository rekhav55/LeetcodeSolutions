class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>indegree(n,0);
        vector<vector<int>>graph(n);
        for(auto edges: roads){
            indegree[edges[0]]++;
            indegree[edges[1]]++;
            graph[edges[0]].push_back(edges[1]);
            graph[edges[1]].push_back(edges[0]);
        }
        int ans = INT_MIN;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                ans = max(ans, indegree[i]+indegree[graph[i][j]]-1);
            }
            for(int k=0;k<graph.size();k++){
                if(find(graph[i].begin(),graph[i].end(),k)==graph[i].end() && k!=i){
                    ans = max(ans, indegree[i]+indegree[k]);
                }
            }
        }
        return ans;
    }
};