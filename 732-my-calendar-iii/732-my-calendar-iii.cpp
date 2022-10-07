class MyCalendarThree {
public:
    map<int,int> mp;  //
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int temp = 0, result = 0;
        mp[start]++;         // for event start => increase the value by 1 of key in map.
        mp[end]--;            // for event end => decrease the value by 1 of key in map.
        
        for(auto m : mp){
            temp += m.second;               // record  the maximum overlapping intervals
            result = max(result, temp);
        }
        return result;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */