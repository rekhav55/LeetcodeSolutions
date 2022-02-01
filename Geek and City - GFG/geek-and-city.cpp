#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>&visited,vector<vector<int>>graph,int src){
    visited[src]=1;
    for(auto it:graph[src]){
        if(visited[it]==0) dfs(visited,graph,it);
    }
}
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n,m;
	    cin>>n>>m;
	    vector<int>visited(n+1,0);
	    vector<vector<int>>graph(n+1);
	    for(int i=0;i<m;i++){
	        int x,y;
	        cin>>x>>y;
	        graph[x].push_back(y);
	        graph[y].push_back(x);
	    }
	    int cnt=-1;
	    for(int i=1;i<=n;i++){
	        if(visited[i]==0){
	            cnt++;
	            dfs(visited,graph,i);
	        }
	    }
	    cout<<cnt<<endl;
	}
	return 0;
}
