class Solution {
public:
    int minimumDeletions(string s) {
        int cnt=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                cnt++;
            }
            else{
                if(cnt>0){
                    cnt--;
                    ans++;
                }
            }
        }
        return ans;
    }
};