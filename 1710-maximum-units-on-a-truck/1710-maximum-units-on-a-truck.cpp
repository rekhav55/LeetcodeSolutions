class Solution {
public:
    static bool comp(const vector<int>&a, const vector<int>&b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int temp=truckSize;
        int sum=0;
        // for(int i=0;i<boxTypes.size();i++){
        //     cout<<boxTypes[i][0]<<" "<<boxTypes[i][1]<<endl;
        // }
        for(int i=boxTypes.size()-1;i>=0;i--){
            if(boxTypes[i][0]<=temp){
                sum = sum+ (boxTypes[i][0]*boxTypes[i][1]);
                temp=temp-boxTypes[i][0];
            }
            else{
                sum = sum+(temp*boxTypes[i][1]);
                break;
            }
        }
        return sum;
    }
};
