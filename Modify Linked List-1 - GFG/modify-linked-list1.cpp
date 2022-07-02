// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node* modifyTheList(struct Node *head);

void push(struct Node **head_ref, int new_data)
{
  struct Node* new_node = new Node(new_data);
  new_node->next = *head_ref;    
  *head_ref = new_node;
}

void printList(struct Node *head)
{
    if (!head)
        return;
   	while (head->next != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data << endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL;
		while(n--){
			int a;
			cin>>a;
			push(&head, a);
		}
		head = modifyTheList(head);
		printList(head);
	}
    return 0;
}

// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
struct Node* reverse(struct Node *head)
{
Node *p=NULL,*t=NULL;
while(head)
{
t=p;
p=head;
head=head->next;
p->next=t;
}
return p;
}
int count(struct Node *head)
{
int cnt=0;
while(head)
{
cnt++;
head=head->next;
}
return cnt;
}
struct Node* modifyTheList(struct Node *head)
{
int cnt=count(head);
struct Node *slow=head,*fast=head,*t;
while(fast && fast->next)
{
if(cnt%2==0)
t=slow;
slow=slow->next;
fast=fast->next->next;
}
if(cnt%2==0)
t->next=NULL;
slow=reverse(slow);
fast=head;
struct Node *end=slow;
while(fast)
{
if(fast!=slow)
fast->data=fast->data-slow->data;
fast=fast->next;
slow=slow->next;
}
end=reverse(end);
if(cnt%2==0)
t->next=end;
return head;
}