class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp,mp1;
        
        
        mp['I'] =  1,    mp1['I'] =  1;
        mp['V'] =  5,    mp1['V'] =  2;
        mp['X'] =  10,   mp1['X'] =  3;
        mp['L'] =  50,   mp1['L'] =  4;
        mp['C'] =  100,  mp1['C'] =  5;
        mp['D'] =  500,  mp1['D'] =  6;
        mp['M'] =  1000, mp1['M'] =  7; 
        
            
        stack<char> st;
        
        
        for(auto x : s){
            st.push(x);
        }
        
        
        int ans = mp[st.top()];
            
        int prev = mp1[st.top()];
        st.pop();
        
        
        while(!st.empty()){
            
            int curr = mp1[st.top()];
            
            if(curr<prev){
                ans-=mp[st.top()];
                
            }
            else{
                ans+=mp[st.top()];
            }
            
            prev = curr;
            
            st.pop();
        }
        
        return ans;
    }
};