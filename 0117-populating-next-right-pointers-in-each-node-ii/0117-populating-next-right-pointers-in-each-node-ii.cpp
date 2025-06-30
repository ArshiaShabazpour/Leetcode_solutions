/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* curr = root;
        Node* head = nullptr; // Head of the next level
        Node* prev = nullptr; // The previous node on the next level

        while (curr) {
            while (curr) {
                // Left child
                if (curr->left) {
                    if (prev) prev->next = curr->left;
                    else head = curr->left;
                    prev = curr->left;
                }

                // Right child
                if (curr->right) {
                    if (prev) prev->next = curr->right;
                    else head = curr->right;
                    prev = curr->right;
                }

                curr = curr->next; // Move in the current level
            }

            // Move to the next level
            curr = head;
            head = nullptr;
            prev = nullptr;
        }

        return root;
    }
};