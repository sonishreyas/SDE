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

2. Find middle of LinkedList 

Ques: Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:
    Input: head = [1,2,3,4,5]
    Output: [3,4,5]
    Explanation: The middle node of the list is node 3.

Example 2:
    Input: head = [1,2,3,4,5,6]
    Output: [4,5,6]
    Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Solution:


* Brute force:
 - Declare a count variable and set it to 1.
 - Traverse the link list and count the number of nodes.
 - set middle = count/2 + 1
 - Traverse the link list till middle.
 - return the remaining link list
 - TC: O(N) + O(N/2) where O(N) is for the first traversal and O(N/2) for second traversal. 

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
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head;
        int count = 1;
        while(temp->next!=NULL){
            count++;
            temp = temp->next;
        }
        int middle = int(count/2) +1;
        temp = head;
        for(int i = 1 ; i<middle ; i++) {
            temp = temp->next;
        }
        
        return temp;
    }
};

* Optimized approach - tortoise approach
- Declare a fast and a slow pointer.
- We will traverse the fast pointer by 2 and slow by 1.
- if number of nodes is odd then we need to end at fast->next == NULL (FOr odd number of nodes in the list) and if even fast == NULL (For even number of nodes in the llist).
- This will reduce the TC to O(N/2) 
- TC: O(N/2)
- SC: O(1)

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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL &&fast->next!= NULL)  {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
};

---------------------------------------------------------------

3. Merge two sorted Linked List  

Ques: Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

Example 1:
    Input: l1 = [1,2,4], l2 = [1,3,4]
    Output: [1,1,2,3,4,4]

Example 2:
    Input: l1 = [], l2 = []
    Output: []

Example 3:
    Input: l1 = [], l2 = [0]
    Output: [0]

Solution:

* Brute force:
 - Declare a new linked list.
 - Traverse the both linked list until one is NULL.
 - compare the values and just assign the lowest to the new linked list
 - if one of them is NULL then just append the other to the new linked list
 - return the new list.
 - TC: O(N).
 - SC: O(N). Since we are using an extra space. 

* Optimized approach - inplace merge
- Make l1 as the samllest of both.
- declare a pointer res and point to l1.
- iterate until one of them is NULL.
- Declare a temp pointer and iterate until l1 is NULL or l1.val <= l2.val
- assign temp = l1 and l1 = l1->next.
- once loop ends assign temp->next = l2
- swap l1 and l2
- TC: O(N)
- SC: O(1)

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val > l2->val)    {
            std::swap(l1,l2);
        }
        ListNode *res = l1;
        while(l1!=NULL && l2 != NULL)   {
            ListNode *temp = NULL;
            while( l1!=NULL && l2->val>= l1->val) {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            std::swap(l1,l2);
        }
        return res;
    }
};

* Optimized with recurrsion:

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return nullptr;
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val<l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

---------------------------------------------------------------
---------------------------------------------------------------
# Day6: (LinkedList)
---------------------------------------------------------------
---------------------------------------------------------------
4. Check if a LinkedList is palindrome or not. 

* Brute force
- We traverse the linked list and append data to an array.
- and compare the array for palindrome.
- TC: O(N)
- SC: O(N)

* Optimized approach
- we find the middle element and then reverse the link list from middle to end.
- now compare the first half and second half.
- TC: O(n/2) [last palindrome loop]+ O(n/2) [middle element]+ O(n/2)[reverse] + O(n/2)[if we have to convert back]
- SC: O(1) 
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
