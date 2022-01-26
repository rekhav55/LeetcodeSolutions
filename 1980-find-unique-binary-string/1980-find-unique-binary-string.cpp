class Solution {
public:
    bool flag=false;
    string f;
    void solve(string op,set<string>&st,int len){
        if(flag) return;
        if(op.length()==len){
            if(st.find(op)==st.end()){
                f=op;
                flag=true;
            }
            return;
        }
        // string op1=op;
        // string op2=op;
        // op1+="0";
        // op2+="1";
        solve(op+"0",st,len);
        solve(op+"1",st,len);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string>st;
        string s = nums[0];
        string op="";
        int len = s.length();
        for(auto it:nums){
            st.insert(it);
        }
        solve(op,st,len);
        return f;
    }
};