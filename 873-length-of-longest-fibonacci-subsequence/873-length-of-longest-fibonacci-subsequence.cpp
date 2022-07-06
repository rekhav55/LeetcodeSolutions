class Solution {
public:
    map<int,int> mp;
    int ans=0;
    int dp[1005][1005];
    
    int func(int i,int j,vector<int> &v){
       
       if (mp.find(v[i]+v[j])==mp.end()){
           return 0;
       }
        
       if (dp[i][j]!=-1){
           return dp[i][j];
       }
        
     return dp[i][j]=1+func(j,mp[v[i]+v[j]],v);
    }
    
    int lenLongestFibSubseq(vector<int>& v) { 
        int i,j;
        memset(dp,-1,sizeof(dp));
        int n=v.size();
        
        for (i=0; i<n; i++){
            mp[v[i]]=i;
        }
        
        for (i=0; i<n-2; i++){
            for (j=i+1; j<n-1; j++){
                if (mp.find(v[i]+v[j])!=mp.end()){
                    ans=max(ans,func(i,j,v));
                }
            }
        }
        
        if (ans==0){
            return 0;
        }
     return ans+2;
    }
};