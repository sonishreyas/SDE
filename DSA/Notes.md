---------------------------------------------------------------
---------------------------------------------------------------
# Day5: (LinkedList)
---------------------------------------------------------------
---------------------------------------------------------------

Ques: Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]

Example 2:
    Input: head = [1,2]
    Output: [2,1]

Example 3:
    Input: head = []
    Output: []

Constraints:

    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000

Solution: 

* Optimized approach:

- Take three pointers p,q, and r. 
- Set p = head, q=head and r= NULL.
- Now set q = p->next, p->next=r, r = p,p=q, until q!=NULL.
- set head = r and return r.

- TC: O(N)

Code:

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
    ListNode* reverseList(ListNode* head) {
        ListNode *p,*q,*r;
        p = head;
        q = head;
        r = NULL;
        while(q!=NULL){
            q = p->next;
            p->next = r;
            r = p;
            p = q;
        }
        head = r;
        return head;
    }
};

---------------------------------------------------------------

2. 