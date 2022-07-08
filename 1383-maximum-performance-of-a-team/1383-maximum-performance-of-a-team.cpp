class Solution {
public:
    int mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long int sum=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            temp.push_back({efficiency[i],speed[i]});
        }
        long long int maxi=0;
        sort(temp.begin(),temp.end(),greater<pair<int,int>>());
        for(int i=0;i<temp.size();i++){
            sum+= temp[i].second;
            pq.push(temp[i].second);
            while(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            maxi = max(maxi, sum*temp[i].first);
        }
        return maxi%mod;
    }
};