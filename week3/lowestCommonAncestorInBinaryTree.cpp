/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* lca(TreeNode* a,int p,int q)
{
    if(!a)
        return NULL;
    TreeNode* left=lca(a->left,p,q);
    TreeNode* right=lca(a->right,p,q);
    if(a->val==p)
        left=a;
    else if(a->val==q)
        right=a;
    if(left && right)
        return a;
    if(!left && !right)
        return NULL;
    if(left)
        return left;
    if(right)
        return right;
    return NULL;
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p->val,q->val);
    }
};
