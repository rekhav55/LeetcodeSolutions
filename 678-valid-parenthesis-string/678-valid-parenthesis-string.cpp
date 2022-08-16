class Solution {
public:
    bool checkValidString(string s) {
        vector<int> open, ast; // using vector to simulate stack, stack can also be used.
    int invalid = 0;
    
    for(int i=0; i<s.length(); ++i){
        if(s[i] == '('){
            open.push_back(i);// storing the indexes of open parenthesis.
        } else if(s[i] == '*'){
            ast.push_back(i);// storing the indexes of asterisks.
        } else {
            if(!open.empty()) open.pop_back();
            else if(!ast.empty()){
                ast.pop_back();
            } else {
                invalid = 1;
                break;
            }
        }
    }
    
    while(!open.empty() and !ast.empty()){
        if(open.back() < ast.back()){
            open.pop_back();
            ast.pop_back();
        } else {
			//else will encounter in this case: *(*(
            break;
        }
    }
    return invalid == 1 ? false : open.empty();
    }
};