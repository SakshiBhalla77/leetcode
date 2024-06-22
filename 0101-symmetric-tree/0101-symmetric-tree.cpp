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
public:
    bool solve(TreeNode* lh, TreeNode* rh )
    {
        if(lh== NULL && rh != NULL) return false;
        if(rh== NULL && lh != NULL) return false;
        if(rh == NULL && lh == NULL) return true;

        if(lh->val != rh->val) return false;

        return (solve(lh->left , rh->right) && solve(lh->right , rh->left));

    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};