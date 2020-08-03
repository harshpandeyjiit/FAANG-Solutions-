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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode* >s1,s2;
        vector<vector<int> >ans;
        if(root==nullptr)
            return ans;
        vector<int>curr;
        s1.push(root);
        int flag=0;
        while(s1.empty()==false)
        {
            while(s1.empty()==false)
            {
                TreeNode* temp=s1.top();
                s1.pop();
                curr.push_back(temp->val);
                if(flag==0)
                {
                    if(temp->left)
                        s2.push(temp->left);
                    if(temp->right)
                        s2.push(temp->right);
                }
                else
                {
                    if(temp->right)
                        s2.push(temp->right);
                    if(temp->left)
                        s2.push(temp->left);
                }
            }
            ans.push_back(curr);
            curr.clear();
            swap(s1,s2);
            flag=1-flag;
        }
        return ans;
    }
};
