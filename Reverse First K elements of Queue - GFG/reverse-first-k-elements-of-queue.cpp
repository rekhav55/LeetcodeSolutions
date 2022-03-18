// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
void reverse(queue<int>&temp){
    if(temp.empty()) return;
    int x = temp.front();
    temp.pop();
    reverse(temp);
    temp.push(x);
}
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    queue<int>temp;
    for(int i=0;i<k;i++){
        temp.push(q.front());
        q.pop();
    }
    reverse(temp);
    while(!q.empty()){
        temp.push(q.front());
        q.pop();
    }
    return temp;
}