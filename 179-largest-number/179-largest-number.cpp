class Solution {
public:
    static bool comp(string &x, string &y){
        string a = x+y;
        string b = y+x;
        if(a.compare(b)>0) return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back(to_string(nums[i]));
        }
        string res="";
        sort(temp.begin(),temp.end(),comp);
        for(int i=0;i<temp.size();i++){
            res+=temp[i];
        }
        
        while(res[0]=='0' && res.size()>1){
            res.erase(res.begin());
        }
        return res;
    }
};