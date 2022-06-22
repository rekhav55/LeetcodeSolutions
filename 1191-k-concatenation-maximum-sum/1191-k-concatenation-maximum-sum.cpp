class Solution {
public:
    int mod = 1e9+7;
    // use kadane algorithm to find the longest continuous number in an array.    
    long kadane (vector<int>& arr){
        int maxEndingHere = 0;
        int maxAll = 0;
        int size = arr.size();
        for(int i=0; i<size; i++){
            maxEndingHere += arr[i]%mod;
            // if the maxEndingHere is smaller than 0, we just reset it.
            if(maxEndingHere < 0) maxEndingHere = 0;
            maxAll = max(maxEndingHere, maxAll);
        }
        return maxAll;
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if(arr.size() == 0) return 0;
        int size = arr.size();
        // case one, k == 1, just input the result.
        if(k==1) return kadane(arr)%mod;
        
		// since we want to check whether the actual sum of the array is larger than 0
        long long sum = accumulate(arr.begin(), arr.end(), 0) % mod; 
		
        // for other cases, we insert the copy of the array into the array.
        for(int i=0; i<size; i++){
            arr.push_back(arr[i]);
        }

        
        int result = 0;
        // sum of original array is larger than 0, we dont need to call the kadane function
        // k - 2 is because we haved doubled the size of the original array by its copy
        if(sum > 0){
            result += (k-2)*sum % mod;
        }

        return (kadane(arr) + result) % mod;
        
    }
};