// bool mycomp(vector<int>&a, vector<int>&b){
//         return a[0]-a[1]<b[0]-b[1];
//     }
class Solution {
public:
    int dp[51][51];
    int findmin(int i, int a, int b,int n,vector<vector<int>>&costs){
        if(i==n) return 0;
        if(dp[a][b]!=-1) return dp[a][b];
        int mini = INT_MAX;
        if(a>0){
            mini =  min(mini,costs[i][0]+findmin(i+1,a-1,b,n,costs));
        }
        if(b>0){
            mini =  min(mini,costs[i][1]+findmin(i+1,a,b-1,n,costs));
        }
        return dp[a][b]=mini;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // int x = costs.size()/2;
        // int cost=0;
        // sort(costs.begin(),costs.end(),mycomp);
        // for(int i=0;i<x;i++){
        //     cost+=costs[i][0]+costs[i+x][1];
        // }
        // return cost;
        int n = costs.size()/2;
        memset(dp,-1,sizeof(dp));
        return findmin(0,n,n,2*n,costs);
        
    }
};