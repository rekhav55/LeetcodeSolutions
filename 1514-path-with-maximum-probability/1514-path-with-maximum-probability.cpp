class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
       vector<vector<pair<int, double>>> graph(n);
        vector<bool> visited(n, false);
        vector<double> dist(n, 0.0);
        
        for(int i = 0 ; i < edges.size() ; i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        dist[start] = 1.0;
        priority_queue<pair<double, int>> maxh;
        maxh.push({dist[start], start});
        
        while(maxh.size())
        {
            auto [distance, node] = maxh.top();
            maxh.pop();
            visited[node] = true;
            
            for(auto [child, to] : graph[node])
            {
                if(!visited[child] && distance*to > dist[child])
                {
                    dist[child] = distance * to;
                    maxh.push({dist[child], child});
                }
            }
            
        }
        
        return dist[end]!=0 ? dist[end] : 0;
    }
};