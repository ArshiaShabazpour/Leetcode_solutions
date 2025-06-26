class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder);
    }

private:
    TreeNode* build(vector<int> preorder, vector<int> inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;

        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);

        int rootIndexInInorder = 0;
        while (inorder[rootIndexInInorder] != rootVal) {
            ++rootIndexInInorder;
        }

        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndexInInorder);
        vector<int> rightInorder(inorder.begin() + rootIndexInInorder + 1, inorder.end());

        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + 1 + leftInorder.size(), preorder.end());

        root->left = build(leftPreorder, leftInorder);
        root->right = build(rightPreorder, rightInorder);

        return root;
    }
};
