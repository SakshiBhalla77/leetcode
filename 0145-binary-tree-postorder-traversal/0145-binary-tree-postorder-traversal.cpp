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
    // void postorder(TreeNode* root, vector<int>&arr)
    // {
    //     if(root == nullptr) return;
    //     postorder(root->left, arr);
    //     postorder(root->right, arr);
    //     arr.push_back(root->val);
        
    // }
    // vector<int> postorderTraversal(TreeNode* root) 
    // {
    //     vector<int> arr;
    //     postorder(root, arr);
    //     return arr;

    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int>postorder;
        if(root == NULL) return postorder;

        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();

            st1.pop();
            st2.push(root);
            if(root->left != NULL){
                st1.push(root->left);
            }
            if(root->right != NULL){
                st1.push(root->right);
            }
        }
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
        

    }
        
    

};