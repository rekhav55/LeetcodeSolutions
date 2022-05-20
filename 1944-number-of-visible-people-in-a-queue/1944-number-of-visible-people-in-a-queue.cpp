class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // int n = (int)heights.size();
        // vector<int>ans(n,0);
        // ans[n-1]=0;
        // stack<int>st;
        // st.push(heights[n-1]);
        // for(int i=n-2;i>=0;i--){
        //     if(heights[i]<st.top()){
        //         ans[i]=1;
        //         st.push(heights[i]);
        //     }
        //     else{
        //         int res=0;
        //         while(st.top()<heights[i]){
        //             st.pop();
        //             res++;
        //         }
        //         ans[i]=res+1;
        //         st.push(heights[i]);
        //     }
        // }
        // return ans;
        stack<int> s;
        //int i=heights.size()-1;
        int n=heights.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
           int count=0;
          //   bool next=false;
               while(!s.empty()&&heights[i]>heights[s.top()]){
                   count++;     
                   s.pop();
              }
              if(!s.empty()){
                  count++;
              }
             ans[i]=count;
             s.push(i);
            
        }
        return ans;
        
    }
};