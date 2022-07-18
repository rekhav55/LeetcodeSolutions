class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        vector<string>res;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                ans+=s[i];
            }
            else{
                if(ans.size()>0) res.push_back(ans);
                ans="";
            }
        }
        if(ans.size()>0) return ans.size();
        int n = res.size();
        string x = res[n-1];
        return x.size();
    }
};