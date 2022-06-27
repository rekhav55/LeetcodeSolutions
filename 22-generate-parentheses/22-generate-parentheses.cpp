class Solution {
public:
    vector<string>ans;
    void f(int open, int close, int n, string s){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            f(open+1,close,n,s+'(');
        }
        if(close<open){
            f(open,close+1,n,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        f(0,0,n,s);
        return ans;
    }
};