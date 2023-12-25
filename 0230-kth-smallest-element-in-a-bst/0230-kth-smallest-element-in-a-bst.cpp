
class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        //BASE CASE
        if(!root) return -1;

        //inorder

        //left
        int leftAns = kthSmallest(root->left,k);
        if(leftAns != -1)
        return leftAns;

        //N->root 
        k--;
        if(k==0){
            return root->val;
        }

        //right
        int rightAns = kthSmallest(root->right, k);
        return rightAns;
        


    }
};