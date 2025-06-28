class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildSubtree(inorder, 0, inorder.size() - 1,
                            postorder, 0, postorder.size() - 1);
    }

private:
    TreeNode* buildSubtree(const vector<int>& inorder, int inL, int inR,
                           const vector<int>& postorder, int postL, int postR) {
        // base case
        if (inL > inR || postL > postR) return nullptr;

        // root value is at end of current postorder segment
        int rootVal = postorder[postR];
        TreeNode* root = new TreeNode(rootVal);

        // find root index in inorder to split left/right
        int i = inL;
        while (i <= inR && inorder[i] != rootVal) ++i;
        int leftSize = i - inL;  // number of nodes in left subtree

        // build left subtree: inorder[inL..i-1], postorder[postL..postL+leftSize-1]
        root->left = buildSubtree(
            inorder, inL,            i - 1,
            postorder, postL,        postL + leftSize - 1
        );

        // build right subtree: inorder[i+1..inR], postorder[postL+leftSize..postR-1]
        root->right = buildSubtree(
            inorder, i + 1,          inR,
            postorder, postL + leftSize, postR - 1
        );

        return root;
    }
};
