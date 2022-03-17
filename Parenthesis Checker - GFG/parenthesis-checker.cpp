// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else if(s[i]==')'){
                if(st.empty()) return false;
                if(st.top()=='(') st.pop();
                else return false;
            }
            else if(s[i]=='}'){
                if(st.empty()) return false;
                if(st.top()=='{') st.pop();
                else return false;
            }
            else if(s[i]==']'){
                if(st.empty()) return false;
                if(st.top()=='[') st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends