class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int curr =0;
        int n = popped.size();
        stack<int>temp;
        for(int i=0;i<pushed.size();i++){
            temp.push(pushed[i]);
            while(!temp.empty() && curr<n && temp.top()==popped[curr]){
                temp.pop();
                curr++; 
            }
        }
        
        if(curr == n) return true;
        return false;
    }
};