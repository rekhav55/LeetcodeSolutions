class Solution {
public:
    bool isPalindrome(string &s,int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void f(int idx,string &s, vector<string>ans,vector<vector<string>>&res){
        if(idx==s.size()){
            res.push_back(ans);
        }
        for(int j=idx;j<s.size();j++){
            if(isPalindrome(s,idx,j)){
                string temp = s.substr(idx,j-idx+1);
                ans.push_back(temp);
                f(j+1,s,ans,res);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>ans;
        f(0,s,ans,res);
        return res;
    }
};