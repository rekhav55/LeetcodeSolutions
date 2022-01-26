class Solution {
public:
    vector<string>res;
    void solve(string ip, string op){
        if(ip.length()==0){
            res.push_back(op);
            return;
        }
        if(isalpha(ip[0])){
            string op1=op;
            string op2=op;
            op1+=tolower(ip[0]);
            op2+=toupper(ip[0]);
            ip.erase(ip.begin()+0);
            solve(ip,op1);
            solve(ip,op2);
        }
        else{
            string op1=op;
            op1+=ip[0];
            ip.erase(ip.begin()+0);
            solve(ip,op1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        string input = s;
        string output = "";
        solve(input,output);
        return res;
    }
};