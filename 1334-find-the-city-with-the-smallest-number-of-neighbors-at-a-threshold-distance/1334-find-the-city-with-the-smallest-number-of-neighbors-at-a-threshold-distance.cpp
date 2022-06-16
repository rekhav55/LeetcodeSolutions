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
    
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        //vector<int> v;
        vector<pair<int,int>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][2],edges[i][1]});
            adj[edges[i][1]].push_back({edges[i][2],edges[i][0]});

        }
        int maxi=INT_MAX,ans;
        for(int i=0;i<n;i++){
            int res = dijkstra(adj,i,k,n);
            if(res<=maxi){
                maxi=res;
                ans = i;
            }
        }
        return ans;
        
        
    }
};