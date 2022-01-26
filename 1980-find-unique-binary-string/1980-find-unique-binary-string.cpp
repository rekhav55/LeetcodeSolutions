class Solution {
public:
    // bool flag=false;
    // string f;
    // void solve(string op,vector<string>&st,int len){
    //     if(flag) return;
    //     if(op.length()==len){
    //         if(find(st.begin(),st.end(),op)==st.end()){
    //             f=op;
    //             flag=true;
    //         }
    //         return;
    //     }
    //     // string op1=op;
    //     // string op2=op;
    //     // op1+="0";
    //     // op2+="1";
    //     solve(op+"0",st,len);
    //     solve(op+"1",st,len);
    // }
    string findDifferentBinaryString(vector<string>& nums) {
        // set<string>st;
        // string s = nums[0];
        // string op="";
        // int len = s.length();
        // // for(auto it:nums){
        // //     st.insert(it);
        // // }
        // solve(op,nums,len);
        // return f;
        string ans;
        for(int i=0;i<nums.size();i++){
            ans+=(nums[i][i]=='0'?'1':'0');
        }
        return ans;
    }
};