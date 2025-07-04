class Solution {
public:
    Node* connect(Node *root) {
        Node *now = root, *head = nullptr, *tail = nullptr;
        while (now) {
            if (now->left) {
                if (tail) tail = tail->next = now->left;
                else      head = tail = now->left;
            }
            if (now->right) {
                if (tail) tail = tail->next = now->right;
                else      head = tail = now->right;
            }
            if (!(now = now->next)) {
                now = head;
                head = tail = nullptr;
            }
        }
        return root;            
    }
};