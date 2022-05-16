/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        Node* prev=NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            prev=NULL;
            for(int i=0;i<sz;i++){
                Node* temp=q.front();
                q.pop();
                temp->next=prev;
                prev=temp;
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
            }
        }
        return root;
    }
};