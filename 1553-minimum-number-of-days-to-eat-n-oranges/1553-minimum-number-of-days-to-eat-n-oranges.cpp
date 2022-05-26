class Solution {
public:
    int fun(int rem, map<int,int>&mp){
        if(rem <=1)
            return rem;
        if(mp[rem] > 0)
            return mp[rem];
        int a = INT_MAX,b=INT_MAX,c=INT_MAX;
       if(rem%2 == 0)
           a = 1+fun(rem - rem/2,mp);
     if(rem%3 == 0)
         b = 1+fun((rem - (2*(rem/3))),mp);
   if((rem%2 !=0) || (rem%3 != 0))
        c = 1+fun(rem -1,mp);
        
        return mp[rem] = min({a,b,c});
    
    }
    int minDays(int n) {
        map<int,int>dp;
        return (int)fun(n,dp);
    }
    
};