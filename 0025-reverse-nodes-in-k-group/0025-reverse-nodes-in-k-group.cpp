class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* group_prev = &dummy;

        while (true) {
            ListNode* kth_node = get_kth_node(group_prev, k);
            if (!kth_node) break;
            ListNode* group_next = kth_node->next;

            ListNode* prev = group_next;
            ListNode* curr = group_prev->next;

            while (curr != group_next) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            ListNode* temp = group_prev->next;
            group_prev->next = kth_node;
            group_prev = temp;
        }

        return dummy.next;
    }

private:
    ListNode* get_kth_node(ListNode* start, int k) {
        while (start && k > 0) {
            start = start->next;
            --k;
        }
        return start;
    }
};
