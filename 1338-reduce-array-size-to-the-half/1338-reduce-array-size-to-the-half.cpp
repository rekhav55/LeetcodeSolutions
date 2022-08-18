class Solution {
public:
     static bool sortbySecond(const pair<int, int> & a, const pair<int, int> & b)
    {
        return (a.second > b.second);
    }
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        for(auto it: arr) mp[it]++;
		// Coping values from the map
        vector<pair<int, int>> mpc(mp.begin(), mp.end());
		// sorting vector pair by 2nd value
        sort(mpc.begin(), mpc.end(), sortbySecond);
        int sum = 0, cnt = 0;
        for(auto it: mpc)
        {
            if(sum < arr.size()/2)
            {
                sum += it.second;
                cnt++;
            }
        }
        return cnt;
    }
};