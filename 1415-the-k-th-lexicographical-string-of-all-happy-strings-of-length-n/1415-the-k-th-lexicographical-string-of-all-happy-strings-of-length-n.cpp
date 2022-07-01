class Solution {
public:
    vector<string> getStrings(int n){
        if(n==1){
            return {"a","b","c"};
        }
        vector<string>ans;
        vector<string>temp = getStrings(n-1);
        for(int i=0;i<temp.size();i++){
            string temp1 = temp[i];
            char ch = temp1[temp1.size()-1];
            if(ch=='a'){
                temp1.push_back('b');
                ans.push_back(temp1);
                temp1.pop_back();
                temp1.push_back('c');
                ans.push_back(temp1);
            }
            else if(ch=='b'){
                temp1.push_back('a');
                ans.push_back(temp1);
                temp1.pop_back();
                temp1.push_back('c');
                ans.push_back(temp1);
            }
            else{
                temp1.push_back('a');
                ans.push_back(temp1);
                temp1.pop_back();
                temp1.push_back('b');
                ans.push_back(temp1);
            }
        }
        return ans;
    }
    string getHappyString(int n, int k) {
        vector<string> res = getStrings(n);
        sort(res.begin(),res.end());
        if(k>res.size()) return "";
        return res[k-1];
        
    }
};