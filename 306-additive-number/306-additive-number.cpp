class Solution {
public:
    vector<long long int>ans; //Resultant Vector
    bool backtrack(string s,int start){   //helper function (perfom backtracking)
        if(start==s.size() and ans.size()>2)return true;  //if we trverse whole string and atleast there are are 3 fibonacci number then return true.
       unsigned long long n=0; //declaring new number
        for(int i=start;i<s.size();i++){ // traverse whole string start from start_index
            n=n*10+s[i]-'0';      // forming new number    
            if(n<0 or n>ULLONG_MAX)return false;  //number goes out of bound
            if(ans.size()<2|| (long long)ans.back()+(long long)ans[ans.size()-2]==n){// checking for fibonacci condition.
                ans.push_back(n);
                if(backtrack(s,i+1))return true; // if number satisfied the conditions then check for further string.
                ans.pop_back();// if number not satisfied the conditions then backtrack to previous state.
            }
            if(s[i]=='0' and i==start)return false;  // checking for trailing zeros/
        }
        return false;
    }
    bool isAdditiveNumber(string s) {
        return backtrack(s,0);
    }
};