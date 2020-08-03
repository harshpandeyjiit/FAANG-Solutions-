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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode* >s;
        vector<int>ans;
        TreeNode* temp=root;
        while(temp!=nullptr || s.empty()==false)
        {
            while(temp)
            {
                s.push(temp);
                temp=temp->left;
            }
            TreeNode* a=s.top();
            if(a->right)
            {
                temp=a->right;
                a->right=NULL;
                continue;
            }
            else
            {
                s.pop();
                ans.push_back(a->val);
                temp=a->right;
            }
        }
        return ans;
    }
};
