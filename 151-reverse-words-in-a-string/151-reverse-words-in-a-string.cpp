class Solution {
public:
    string reverseWords(string s) {
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
        if(ans.size()>0) res.push_back(ans);
        int n = res.size();
        string temp="";
        for(int i=n-1;i>=0;i--){
            temp+=res[i];
            if(i!=0) temp+=" ";
        }
        return temp;
    }
};