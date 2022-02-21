// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool detectCycle(vector<int>&visited,vector<int>&dfsVisited,int node,vector<int>adj[]){
        visited[node]=1;
        dfsVisited[node]=1;
        for(auto it:adj[node]){
            if(visited[it]==0){
                if(detectCycle(visited,dfsVisited,it,adj)) return true;
            }
            else if(visited[it]==1 && dfsVisited[it]==1){
                return true;
            }
        }
        dfsVisited[node]=0;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>adj[N];
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    vector<int>visited(N,0);
	    vector<int>dfsVisited(N,0);
	    for(int i=0;i<N;i++){
	        if(visited[i]==0){
	            if(detectCycle(visited,dfsVisited,i,adj)) return false;
	        }
	    }
	    
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends