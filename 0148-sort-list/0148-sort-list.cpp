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
    // Merge two sorted linked lists
    ListNode* mergeSortedLists(ListNode* left, ListNode* right) {
        ListNode dummy(-1);
        ListNode* current = &dummy;

        while (left && right) {
            if (left->val < right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        // Attach the remaining nodes
        current->next = (left) ? left : right;

        return dummy.next;
    }

    // Find the middle node of the list (for splitting)
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Main sort function using merge sort
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Split the list into two halves
        ListNode* mid = findMiddle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr;

        // Recursively sort each half
        left = sortList(left);
        right = sortList(right);

        // Merge the two sorted halves
        return mergeSortedLists(left, right);
    }
};