class Solution {
public:
    
    int dijkstra(vector<pair<int,int>> adj[], int src, int k, int n){
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        dist[src]=0;
        
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            for(auto it:adj[u]){
                int v=it.second;
                int wt=it.first;
                if(dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        
        int cities=0;
        for(int i=0;i<n;i++){
            if(dist[i]<=k){
                cities++;
            }
        }
        return cities-1;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int ki) {
        //vector<int> v;
//         vector<pair<int,int>> adj[n];
//         for(int i=0;i<edges.size();i++){
//             adj[edges[i][0]].push_back({edges[i][2],edges[i][1]});
//             adj[edges[i][1]].push_back({edges[i][2],edges[i][0]});

//         }
//         int maxi=INT_MAX,ans;
//         for(int i=0;i<n;i++){
//             int res = dijkstra(adj,i,k,n);
//             if(res<=maxi){
//                 maxi=res;
//                 ans = i;
//             }
//         }
//         return ans;
        vector<vector<int>>graph(n, vector(n, 100000));
        for(int i=0; i<edges.size(); i++)
            graph[edges[i][0]][edges[i][1]] = graph[edges[i][1]][edges[i][0]] = edges[i][2];
        for(int i=0; i<n; i++)
            graph[i][i] = 0;
        
        for(int k = 0; k < n; ++k)       // Floyd Warshalls Algo to Find All Pair Shortest Path
         for(int i = 0; i < n; ++i)
          for(int j = 0; j < n; ++j)  
           graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        
        int ans = 0, minm = n; 
        for(int i=0; i<n; i++)
        {                                 // Updating the answer
            int count = 0;
            for(int j=0; j<n; j++)
             if(graph[i][j]<=ki)
               count++;
            if(count<=minm)
             {minm = count; ans = i;}
        }
        
       return ans;
        
        
        
    }
};