class Solution {
public:
    void lexicalHelper(int cur,int n,vector<int> &ans){
        //Base case : If current number get higher than n we simple return
        if(cur>n)
            return;

        //Otherwise we push the current element in ans vector.
        ans.push_back(cur);

        //we recursively call helper function to find all number starting with current.
        for(int i=0;i<10;i++){
            int nextNum = cur*10+i;

        //If at any instance our next number get bigger then n, we simple return.
            if(nextNum>n)
                return;

            lexicalHelper(nextNum,n,ans);
        }
    }
    
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        
        for(int i=1;i<10;i++)
        //Call Recursive Helper function to find all number starting with i present till n.
            lexicalHelper(i,n,ans);
        
        return ans;
    }
};