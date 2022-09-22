class Solution {
public:
     void solve(string &s, int i, int n){
        while(i<n){
            swap(s[i],s[n]);
            i++;
            n--;
        }
    }
    string reverseWords(string s) {
        int n=s.size();
        int j = 0;
        int i;
        for(i=0; i<n; i++){
            if(i==0 && s[i]==' '){
                j = i+1;
                continue;
            };
            cout<<i<<j<<" ";
            if(s[i]==' '){
                solve(s,j,i-1);
                j = i+1;
            }
        }
        cout<<s[i]<<s[j];
        solve(s,j,i-1);
        return s;
    }
};