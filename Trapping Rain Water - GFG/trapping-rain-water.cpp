// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        // vector<long long>left(n);
        // vector<long long>right(n);
        // left[0]=arr[0];
        // right[n-1]=arr[n-1];
        // for(int i=1;i<n;i++){
        //     if(left[i-1]>arr[i]) left[i]=left[i-1];
        //     else left[i]=arr[i];
        // }
        // for(int i=n-2;i>=0;i--){
        //     if(right[i+1]>arr[i]) right[i]=right[i+1];
        //     else right[i]=arr[i];
        // }
        
        // long long sum=0;
        // vector<long long>ans(n,0);
                        
        // for(int i=0;i<n;i++){
        //     if(left[i]<right[i]){
        //         ans[i]= left[i]-arr[i];
        //     }
        //     else ans[i]=right[i]-arr[i];
        // }
        // for(int i=0;i<n;i++) sum+=ans[i];
        // return sum;
        int low = 0, high=n-1;
        int left_max=0, right_max=0;
        long long sum = 0;
        while(low<=high){
            if(arr[low]<arr[high]){
                if(arr[low]>left_max) left_max=arr[low];
                else sum+= left_max-arr[low];
                low++;
            }
            else{
                if(arr[high]>right_max) right_max = arr[high];
                else sum+= right_max-arr[high];
                high--;
            }
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends