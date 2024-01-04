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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int length = q.size();
            vector<int>level(length);
            for(int i =0; i<length; i++)
            {
                TreeNode* front = q.front(); 
                q.pop();

                int index;
                if(flag == true)
               index = i;

                else
                index = length - i -1;
                level[index] = front ->val;

                if(front ->left)  q.push(front ->left);
                if(front->right)  q.push(front-> right);

            }
            flag = !flag;
            ans.push_back(level);
        }
        return ans;

    }
};