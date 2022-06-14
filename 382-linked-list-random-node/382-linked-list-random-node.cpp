/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int n = 0;
    ListNode *h1 = new ListNode();
    Solution(ListNode *head)
    {
        h1=head;
        ListNode *curr = head;
        while (curr != NULL)
        {
            n++;
            curr = curr->next;
        }
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        int r = (rand()) % n; // random number between 0 to n
        ListNode *curr = h1;
        while (r--)
        {
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */