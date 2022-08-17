class Solution {
public:
    set<string>st;
    void f(int idx, string &s, string ans, vector<string>&res){
        if(idx==s.size()){
            ans.pop_back();
            res.push_back(ans);
        }
        
        for(int j=idx;j<s.size();j++){
            string temp = s.substr(idx,j-idx+1);
            if(st.find(temp)!=st.end()){
                f(j+1,s,ans+temp+" ",res);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto it:wordDict){
            st.insert(it);
        }
        
        vector<string>res;
        string ans="";
        f(0,s,ans,res);
        return res;
    }
};