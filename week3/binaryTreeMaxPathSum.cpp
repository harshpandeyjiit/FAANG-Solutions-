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
int solve(TreeNode* root,int& ans)
{
    int left=0;
    int right=0;
    if(root==nullptr)
        return 0;
    left=solve(root->left,ans);
    right=solve(root->right,ans);
    ans=max(ans,max(root->val,max(max(left,right)+root->val,left+right+root->val)));
    return max(root->val,max(left,right) + root->val);
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};
