static bool seen[100001];
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
    ListNode* deleteNode(ListNode* prev, ListNode* n) {
        ListNode* next=n->next;
        prev->next=next;
        return next;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        fill(seen, seen+100001, 0);
        for (int v:nums) seen[v]=1;
        ListNode* dummy= new ListNode(0, head);
        ListNode* curr=head;
        ListNode* prev=dummy;
        while (curr != nullptr) {
            if (seen[curr->val]) {
                curr=deleteNode(prev, curr);
            } else {
                prev=curr;
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};