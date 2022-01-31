class Solution {
public:
    void dfs(vector<int>adj[],vector<bool>&vist,int start)
    {
        vist[start]=true;
        for(auto i:adj[start])
        {
            if(!vist[i])
                dfs(adj,vist,i);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        int ans=0;
        vector<bool>vist(n,false); //to keep track of the nodes that has been visited
        vector<int>adj[n]; //adjacency list
        
        if(connections.size()+1<n) return -1;
        //creating adjacency list
        for(auto i:connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        for(int i=0;i<n;i++)  //i->0-4  ; 0-1-2-3
        {
            if(!vist[i])
            {
                dfs(adj,vist,i);
                ans++;
            }
        }
    return ans-1;
    }
};
