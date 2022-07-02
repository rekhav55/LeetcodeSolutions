class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        if(n==2){
            return "11";
        }
        string ans="";
        string res = countAndSay(n-1);
        int cnt =1;
        int i;
        for(i=0;i<res.size();i++){
            if(i+1<res.size() && res[i]!=res[i+1]){
                ans+= to_string(cnt)+res[i];
                cnt=1;
            }
            else if(i+1<res.size() && res[i]==res[i+1]){
                cnt++;
            }
        }
        ans+= to_string(cnt)+res[i-1];
        return ans;
    }
};