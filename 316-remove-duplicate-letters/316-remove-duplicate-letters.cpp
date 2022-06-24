class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>freq(26,0);
        vector<bool>seen(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']=i;
        }
        
        stack<char>st;
        
        for(int i=0;i<s.size();i++){
            if(seen[s[i]-'a']==true) continue;
            while(!st.empty() && st.top()>s[i] && freq[st.top()-'a']>i){
                char x = st.top();
                st.pop();
                seen[x-'a']=false;
            }
            if(st.empty()==true || seen[s[i]-'a']==false){
                st.push(s[i]);
                seen[s[i]-'a']=true;
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};