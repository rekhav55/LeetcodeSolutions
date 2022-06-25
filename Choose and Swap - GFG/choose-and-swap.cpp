// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string s){
        // Code Here
        bool a[200] = {0}, done[200] = {0};
        for(auto &c : s) a[c] = 1;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(done[c]) continue;
            for(int j = 'a'; j < c; j++){
                if(a[j] && !done[j]){
                    string res = "";
                    for(auto &ch : s){
                        if(ch == c) res += (char)j;
                        else if(ch == (char)j) res += c;
                        else res += ch;
                    }
                    return res;
                }
            }
            done[c] = 1;
        }
        return s;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends