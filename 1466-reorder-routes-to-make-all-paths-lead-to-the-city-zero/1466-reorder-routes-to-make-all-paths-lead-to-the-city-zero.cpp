class Solution {
public:
   int minReorder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        int count = 0;
        vector<int> visited(n, 0);
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(-u);
        }
        
        dfs(0, adjList, visited, count);
        return count;
    }
    
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited, int& count){
        visited[node] = 1;
        vector<int> neighbors = adjList[node];
        
        for(auto& neighbor: neighbors){
            if(visited[abs(neighbor)] == 0){
                if(neighbor>0)count += 1;
                dfs(abs(neighbor), adjList, visited, count);
                
            }
        }
    }
    
    // bool needsToPointInReverseDirection(int node){
    //     if(node > 0) return true;
    //     return false;
    // }
};