class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* node, int curSum) {
        if (!node) 
            return 0;
        
        int newSum = curSum * 10 + node->val;
        
        if (!node->left && !node->right)
            return newSum;
        
        return dfs(node->left,  newSum)
             + dfs(node->right, newSum);
    }
};
