class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        while (lists.size() > 1) {
            ListNode* l1 = lists.front();
            lists.erase(lists.begin()); 
            ListNode* l2 = lists.front();
            lists.erase(lists.begin()); 
            lists.push_back(mergeLists(l1, l2));
        }

        return lists.front(); 
    }

private:
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* node = &dummy;

        while (l1 && l2) {
            if (l1->val > l2->val) {
                node->next = l2;
                l2 = l2->next;
            } else {
                node->next = l1;
                l1 = l1->next;
            }
            node = node->next;
        }

        node->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
