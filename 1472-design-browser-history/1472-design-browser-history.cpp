class BrowserHistory {
 vector<string> history;
    int cur;
    
public:
    BrowserHistory(string homepage) {
        history.clear();
        history.push_back(homepage);
        cur = 0;
    }
    
    void visit(string url) {        
        history.erase(history.begin()+cur+1,history.end());
        history.push_back(url);
        cur += 1;
    }
    
    string back(int steps) {
        if (steps > cur)
            steps = cur;
        cur -= steps;
        return history[cur];
    }
    
    string forward(int steps) {
        int maxSteps = history.size() - cur - 1;
        if (steps > maxSteps)
            steps = maxSteps;
        cur += steps;
        return history[cur];
    }
//     vector<string>browser;
//     int cur=0;
//     BrowserHistory(string homepage) {
//         browser.clear();
//         browser.push_back(homepage);
//         cur=0;
//     }
    
//     void visit(string url) {
//         browser.erase(browser.begin()+cur+1,browser.end());
//         browser.push_back(url);
//         cur++;
//     }
    
//     string back(int steps) {
//         int x;
//         if(steps<=cur){
//             cur-=steps;
//         }
//         else{
//             cur=0;
//         }
//         return browser[x];
//     }
    
//     string forward(int steps) {
//         int max_steps= browser.size()-1-cur;
//         if(steps>max_steps) steps=max_steps;
//         else steps-=max_steps;
//         return browser[steps];
//     }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */