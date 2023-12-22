// approach 1 - inorder traversal O(n)
/*
case 1 - val in range (add that node and all RE for left and right)
case 2 - val < low (RE for right subtree only)
case 3 - val > high (RE for left subtree only)
*/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int ans = 0;

        bool wasInRange = false;
        //case 1 
        if(root->val >= low && root->val <= high){
            wasInRange = true;
            ans += root->val;
        }

        if(wasInRange){
            ans+= rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        
        //case 2 
        else if(root->val < low){
            ans += rangeSumBST(root->right, low,high);
        }
        else if(root->val > high){
            ans+= rangeSumBST(root->left , low, high);
        }
        

        return ans;

    }
};