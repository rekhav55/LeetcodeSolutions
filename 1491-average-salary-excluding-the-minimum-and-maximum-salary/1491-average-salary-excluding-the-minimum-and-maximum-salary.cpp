class Solution {
public:
    double average(vector<int>& salary) {
        double avg = 0.00000;
        int mini = salary[0];
        int maxi = salary[0];
        for(int i=0;i<salary.size();i++){
            avg+=salary[i];
            mini = min(mini,salary[i]);
            maxi = max(maxi,salary[i]);
        }
        avg-=mini;
        avg-=maxi;
        avg/=(salary.size()-2);
        return avg;
    }
};