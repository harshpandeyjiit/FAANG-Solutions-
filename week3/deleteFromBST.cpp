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
TreeNode* deleteNodeQ(TreeNode* root,int key)
{
    if(root==nullptr)
        return root;
    if(root->val<key)
        root->right = deleteNodeQ(root->right,key);
    else if(root->val>key)
        root->left = deleteNodeQ(root->left,key);
    else if(root->val==key)
    {
        if(root->left==nullptr && root->right==nullptr)
            return root->left;
        if(root->left && root->right)
        {
            TreeNode* temp=root->right;
            while(temp && temp->left!=nullptr)
                temp=temp->left;
            int a=root->val;
            root->val=temp->val;
            temp->val=a;
            root->right=deleteNodeQ(root->right,a);
            return root;
        }
        if(root->left)
        {
                TreeNode* temp = root->left;
            delete(root);
            return temp;
        }
        if(root->right)
        {
            TreeNode* temp=root->right;
            delete(root);
            return temp;
        }

    }
    return root;
}
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* newRoot = deleteNodeQ(root,key);
        return newRoot;
    }
};
