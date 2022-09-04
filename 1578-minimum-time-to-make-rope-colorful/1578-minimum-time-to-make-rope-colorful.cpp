class Solution {
public:
    int minCost(string c, vector<int>& nt) {
         stack<int> stc;
         int n = c.length();
         int sum = 0;

        stc.push(0);
        for(int i=1;i<n;i++)
        {
            if(c[i]!=c[stc.top()])
                stc.push(i);
            else
            {
                if(nt[i]>=nt[stc.top()])
                {
                    sum+=nt[stc.top()];
                    stc.pop();
                    stc.push(i);
                }
                
                else
                {
                    sum+=nt[i];
                }
            }
        }
        return sum;
    }
};