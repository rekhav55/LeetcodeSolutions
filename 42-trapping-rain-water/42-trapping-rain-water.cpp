class Solution {
public:
    int trap(vector<int>& height) {
        int low =0;
        int high = height.size()-1;
        int left_max=0,right_max=0,res=0;
        while(low<=high){
            if(height[low]<height[high]){
                if(height[low]>left_max) left_max=height[low];
                else res+= (left_max-height[low]);
                low++;
            }
            else{
                if(height[high]>right_max) right_max=height[high];
                else res+= (right_max-height[high]);
                high--;
            }
        }
        return res;
    }
};