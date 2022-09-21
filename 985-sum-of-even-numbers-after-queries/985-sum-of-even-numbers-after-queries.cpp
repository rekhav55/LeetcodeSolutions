class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
         int n = nums.size();
        int sum = 0;
        
        for(int i=0; i<n; i++) {
            if(nums[i]%2==0) { // If Even then Add
                sum += nums[i];
            }
        }
        
        vector<int> ans;
        
        for(int i=0; i<queries.size(); i++) {
            
            int val = queries[i][0];
            int index = queries[i][1];
            
            // We have 3 cases to consider here
            // Bcoz of queries the element from nums vector
            // Case 1: is changing from Odd to Even
            // Case 2: is changing from Even to Even(value changed but still even)
            // Case 3: is changing from Even to Odd
            
            //After Adding, It is even (Case 1 or 2)
            if( (nums[index]+val) %2 == 0 ) { 
                
                if( nums[index] %2 == 0 ) { // Initially, It was even (Case 2)
                    sum += val; 
                }
                else { // Initially, It was Odd (Case 1)
                    sum += nums[index] + val;
                }   
            }
            // After Adding, It is Odd (Case 3)
            else if( (nums[index]+val) %2 != 0 ) { 
                
                if( nums[index] %2 == 0 ) { // Initially, It was even
                    sum -= nums[index];
                }   
            }
            
            nums[index] += val; // Update the element
            ans.push_back(sum);
        }
        return ans;
    }
};