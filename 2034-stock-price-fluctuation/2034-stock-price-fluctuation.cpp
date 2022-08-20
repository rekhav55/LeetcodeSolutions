class StockPrice {
public:
     priority_queue<pair<int, int>> pq1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
    unordered_map<int,int> m;
    int curr=INT_MIN;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        m[timestamp]=price;
        pq1.push({price,timestamp});
        pq2.push({price,timestamp});
        curr=max(curr,timestamp);
        
    }
    
    int current() {
       return m[curr];
    }
    
    int maximum() {
        while(pq1.top().first!=m[pq1.top().second]){
            pq1.pop();
        }
        return pq1.top().first;
    }
    
    int minimum() {
        while(pq2.top().first!=m[pq2.top().second]){
            pq2.pop();
        }
        return pq2.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */