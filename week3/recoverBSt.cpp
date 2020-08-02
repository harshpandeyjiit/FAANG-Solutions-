void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
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
void recover(TreeNode* root,TreeNode** first,TreeNode** middle,TreeNode** third,TreeNode** prev)
{
    if(root)
    {
        recover(root->left,first,middle,third,prev);
        if(*prev && root->val < (*prev)->val)
        {
            if(!*first)
            {
                *first=*prev;
                *middle=root;
            }
            else
                *third=root;
        }
        *prev=root;
        recover(root->right,first,middle,third,prev);
    }
}
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first,*middle,*third,*prev;
        first=middle=third=prev=nullptr;
        recover(root,&first,&middle,&third,&prev);
        if(first && third)
        {
            swap(&(first->val),&(third->val));
        }
        else if(first && middle)
        {
            swap(&(first->val),&(middle->val));
        }
    }
};
