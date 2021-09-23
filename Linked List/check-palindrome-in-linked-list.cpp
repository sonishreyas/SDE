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
        while(q!= NULL) {
            q = p->next;
            p->next = r;
            r = p;
            p = q;
        }
        head = r;
        return head;
    }
    
    ListNode* middleElement(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next!= NULL && fast->next->next!=NULL)    {
            slow = slow->next;
            fast = fast->next->next;
        }
        head = slow->next;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next==NULL) return true;
        
        bool ans = false;
        ListNode* temp = head;
        ListNode* mid = middleElement(head);
        ListNode* rev = reverseList(mid);
        while(rev!=NULL)    {
            if(rev->val == temp->val)   {
                ans = true;
                rev = rev->next;
                temp = temp->next;
            }
            else    {
                ans = false;
                break;
            }
        }
        
        return ans;
    }
};