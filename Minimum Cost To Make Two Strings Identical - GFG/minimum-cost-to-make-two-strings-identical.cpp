// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int lcs(string x, string y){
	    int m = x.size();
	    int n = y.size();
	    int L[m+1][n+1];
	    for(int i=0;i<=m;i++){
	        for(int j=0;j<=n;j++){
	            if(i==0||j==0){
	                L[i][j]=0;
	            }
	            else if(x[i-1]==y[j-1]){
	                L[i][j]=1+L[i-1][j-1];
	            }
	            else{
	                L[i][j]=max(L[i-1][j],L[i][j-1]);
	            }
	        }
	    }
	    return L[m][n];
	}
	int findMinCost(string X, string Y, int costX, int costY)
	{
	    // Your code goes here
	    int l = lcs(X,Y);
	    int del = X.size()-l;
	    int ins = Y.size()-l;
	    return (del*costX)+(ins*costY);
	}
  

};
	

// { Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
       	string x, y;
       	cin >> x >> y;
        
       	int costX, costY;
       	cin >> costX >> costY;

        

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends