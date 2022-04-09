class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        vector<int> dp(365,-1);
        return helper(days,costs, 0, days.size()-1 ,dp);
    }
    
    int helper(vector<int>& d, vector<int>& costs, int pos , int n, vector<int>& dp )
    {
        if(pos > n )
            return 0;  
        
        int a = costs[0];
        int b = costs[1];
        int c = costs[2];
        
        // check if the memoization result is already present 
        if(dp[pos] != -1)
            return dp[pos];
        
        a += helper(d,costs, pos +1,n,dp );
        
        
        // pick the next index assuming we bought 7 day ticket on current pos 
        for(int i= pos+1; i <= n; i ++)
        {
            if( -d[pos] + d[i] >= 7 )
            {
                b += helper(d,costs, i , n,dp);
                break;
            }
        }
           
          // pick the next index assuming we bought 30 day ticket on current pos 
        for(int i= pos+1; i <= n; i ++)
        {
            if(-d[pos] + d[i] >= 30 )
            {
                c += helper(d,costs, i , n,dp);
                break;
            }
        }
        
        // ans will be the minimum of these 
       return dp[pos]  = min (a, min(b,c));
    }
};