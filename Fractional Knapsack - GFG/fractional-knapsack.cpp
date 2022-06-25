// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>>temp;
        for(int i=0;i<n;i++){
            double x = (arr[i].value*1.0)/(arr[i].weight*1.0);
            temp.push_back({x,i});
        }
        
        sort(temp.begin(),temp.end(),greater<pair<double,int>>());
        double profit=0;
        int wt =0;
        
        for(int i=0;i<n;i++){
            int idx = temp[i].second;
            if(wt+arr[idx].weight<W){
                wt+=arr[idx].weight;
                profit+=arr[idx].value;
            }
            else{
                double x = W-wt;
                profit = profit+ (temp[i].first*x);
                break;
            }
        }
        return profit;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends