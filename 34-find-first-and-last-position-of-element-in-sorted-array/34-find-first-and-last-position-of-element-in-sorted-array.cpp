class Solution {
public:
   int firstLastOcc(vector<int> &r,int siz,int target,string Y){
      int start=0,end=siz-1,res=-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
         if(r[mid]==target && Y=="firstOcc")
            {
             res=mid;
             end=mid-1;
            }
            else if(r[mid]==target && Y=="lastOcc")
            {
                res=mid;
                start=mid+1;
            }
            else if(r[mid]>target)
            {
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       int f=firstLastOcc(nums,nums.size(),target,"firstOcc");
        int l=firstLastOcc(nums,nums.size(),target,"lastOcc");
        
        return {f,l};
    
    }
};