class Solution {
public:
    void helper(int ind, string &s, vector<string> &temp, vector<string> &ans){
    //base case
    if (ind == s.size() and temp.size() == 4){
        string validIP = temp[0] + '.' + temp[1] + '.' + temp[2] + '.' + temp[3];
        ans.push_back(validIP);
        return;
    }
    
    string tempStr = "";
    for (int i=ind ; i<s.size() and temp.size() < 4 ; i++){
        if (s[i] - '0' > 9) continue;
        tempStr += s[i];
        int tempInt = stoi(tempStr);
        
        //check if the number is between 0 to 255 or not
        //if true then insert it to temp call recursively for i+1 and then backtrack
        if (0 <= tempInt and tempInt <= 255){
            temp.push_back(tempStr);
            helper(i+1, s, temp, ans);
            temp.pop_back();  //backtrack
        }
        
        if (tempInt <= 0 or tempInt > 255){
            break;
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    vector<string> temp;
    helper(0, s, temp, ans);
    return ans;
}
};