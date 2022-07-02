class Solution {
public:
    bool lcs(string a, string b){
        int n = a.size();
        int m = b.size();
        int j=0;
        if(n>m) return false;
        for(int k=0;k<m;k++){
            if(b[k]==a[j]){
                j++;
                if(j==n) return true;
            }
        }
        return false;
    }
    int findLUSlength(vector<string>& strs) {
        int ans=-1;
        for(int i=0;i<strs.size();i++){
            bool flag=true;
            for(int j=0;j<strs.size();j++){
                if(i==j) continue;
                if(lcs(strs[i],strs[j])){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans = max(ans, (int)strs[i].size());
            }
        }
        return ans;
    }
};