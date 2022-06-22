class Solution {
public:
    vector<int> dp;
    int solve(string s,int index)
    {
        if(index==s.size())
            return 1;
        if(s[index]=='0')
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int decode=solve(s,index+1);
        int combine=0;
        if(index<s.size()-1)
        {
            string str;
            str.push_back(s[index]);
            str.push_back(s[index+1]);
            if(str>="1" && str<="26")
                combine=solve(s,index+2);
            else
                combine=0;
        }
        return dp[index]=decode+combine;
    }
    int numDecodings(string s) {
        int n=s.size();
        dp=vector<int>(n+1,-1);
        if(s[0]=='0')
            return 0;
        return solve(s,0);
    }
};