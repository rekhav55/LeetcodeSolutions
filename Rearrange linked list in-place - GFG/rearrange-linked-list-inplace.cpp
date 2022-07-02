// { Driver Code Starts
#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


Node *inPlace(Node *root);
 
void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main() {
	// your code goes here
	int T;
	cin>>T;
 
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Node *res = inPlace(head);
		print(res);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/


Node *findmid(Node *root){
    Node *slow = root, *fast = root->next;
    while(fast!= NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *reverse(Node *root){
    Node *curr = root, *prev = NULL, *succ;
    while(curr!=NULL){
        succ = curr->next;
        curr->next = prev;
        prev = curr;
        curr = succ;
    }
    return prev;
}
Node *inPlace(Node *root)
{
 	// your code goes here
    Node *mid = findmid(root);
    Node *q = reverse(mid->next);
    mid->next = NULL;
    Node *t = root;
    while(t!= NULL && q!=NULL){
        Node *p = t->next;
        t->next = q;
        Node *l = q->next;
        q->next = p;
        t = p;
        q = l;
    }
    return root;
}
