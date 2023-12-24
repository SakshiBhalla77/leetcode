//BST -two key things 1- inorder is sorted , bst ke right me badi values hoti 
/*
case 1 p < root->data && q < root->data     left ki call krdo
case 2 p > root && q > root    right ki call
case 3 p < root && q > root   return root
case 4 p > root && q < root   return root
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(!root) return NULL;

        //case 1
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }

        //case 2
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }

        else{
            return root;
        }



    }
};