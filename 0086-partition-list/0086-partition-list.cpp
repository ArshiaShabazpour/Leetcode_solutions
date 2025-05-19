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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummyL(0), dummyR(0);
        ListNode *left = &dummyL, *right = &dummyR;
        
        while (head) {
            if (head->val < x) {
                left->next = head;
                left = head;
            } else {
                right->next = head;
                right = head;
            }
            head = head->next;
        }
        
        right->next = nullptr;
        left->next = dummyR.next;
        
        return dummyL.next;
    }
};
