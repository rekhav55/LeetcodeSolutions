// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        struct Node* temp = NULL;
        stack<int>firstL;
        stack<int>secondL;
        struct Node* f = first;
        struct Node* s = second;
        while(f!=NULL){
            firstL.push(f->data);
            f=f->next;
        }
        
        while(s!=NULL){
            secondL.push(s->data);
            s=s->next;
        }
        
        int carry=0;
        
        while(!firstL.empty() && !secondL.empty()){
            int x = firstL.top();
            int y = secondL.top();
            firstL.pop();
            secondL.pop();
            int res = x+y+carry;
            carry = res/10;
            res = res%10;
            struct Node* t = new Node(res);
            t->next = temp;
            temp=t;
        }
        
        while(!firstL.empty()){
            int x = firstL.top();
            firstL.pop();
            int res = x+carry;
            carry=res/10;
            res=res%10;
            struct Node* t = new Node(res);
            t->next=temp;
            temp=t;
        }
        while(!secondL.empty()){
            int x = secondL.top();
            secondL.pop();
            int res = x+carry;
            carry=res/10;
            res=res%10;
            struct Node* t = new Node(res);
            t->next=temp;
            temp=t;
        }
        
        if(carry==1){
            struct Node* t = new Node(1);
            t->next=temp;
            temp=t;
        }
        
        return temp;
        
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends