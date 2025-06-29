/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int,int> umap;//val->ind
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            umap[inorder[i]]=i;
        }
        int ind=postorder.size()-1;
        return build(postorder, ind, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int> &postorder, int& ind, int st, int end){
        if(ind<0 || st>end){return NULL;}
        else{
            TreeNode *node = new TreeNode(postorder[ind]);
            int mid = umap[postorder[ind]];
            ind--;
            node->right = build(postorder, ind, mid+1, end);
            node->left = build(postorder, ind, st, mid-1);
            
            return node;
        }
    }
};