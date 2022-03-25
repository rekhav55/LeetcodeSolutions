bool mycomp(vector<int>&a, vector<int>&b){
        return a[0]-a[1]<b[0]-b[1];
    }
class Solution {
public:
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int x = costs.size()/2;
        int cost=0;
        sort(costs.begin(),costs.end(),mycomp);
        for(int i=0;i<x;i++){
            cost+=costs[i][0]+costs[i+x][1];
        }
        return cost;
    }
};