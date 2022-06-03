class NumArray {
public:
    vector<int>res;
    NumArray(vector<int>& nums) {
        res = nums;
        for(int i=1;i<res.size();i++){
            res[i]+=res[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        int sum =0;
        if(left==0) return res[right];
        return res[right]-res[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */