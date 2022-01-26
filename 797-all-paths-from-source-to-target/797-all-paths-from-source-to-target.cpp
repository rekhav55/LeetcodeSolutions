class Solution {
public:
    vector<vector<int>>paths;
    vector<int>temp;
    void dfs(int src, int dest, vector<bool>&visited, vector<vector<int>>&graph){
        visited[src]=true;
        temp.push_back(src);
        if(src==graph.size()-1){
            paths.push_back(temp);
        }
        for(int i: graph[src]){
            if(!visited[i]){
                dfs(i,graph.size()-1,visited,graph);
            }
        }
        visited[src]=false;
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool>visited(graph.size(),0);
        
        dfs(0,graph.size()-1,visited,graph);
        return paths;
    }
};