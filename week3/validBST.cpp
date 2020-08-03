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
#define ll long long
const ll r = 1000000000000000;
const ll l = -1000000000000000;
void check(TreeNode* root,ll low,ll high,int& flag)
{
    if(root==NULL)
            return;
    if(root->val>low && root->val<high)
    {
        check(root->left,low,root->val,flag);
        check(root->right,root->val,high,flag);
    }
    else
    {
        flag=1;
        return;
    }
    return;
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int flag=0;
        check(root,l,r,flag);
        if(!flag)
            return true;
        return false;
    }
};
