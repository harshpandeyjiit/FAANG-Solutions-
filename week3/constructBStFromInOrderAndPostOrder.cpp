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
TreeNode* fun(vector<int>& inOrder,vector<int>& postOrder,int s,int e,int& index)
{
    if(s>e || index==-1)
        return NULL;
    if(s==e)
    {
        index--;
        return new TreeNode(inOrder[s]);
    }
    index--;
    int inIndex=-1;
    for(int i=s;i<=e;i++)
        if(inOrder[i]==postOrder[index])
            inIndex=i;
    TreeNode* root=new TreeNode(inOrder[inIndex]);
    //index--;
    root->right=fun(inOrder,postOrder,inIndex+1,e,index);
  //  index--;
    root->left=fun(inOrder,postOrder,s,inIndex-1,index);
    return root;

}
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=postorder.size();
        TreeNode* root= fun(inorder,postorder,0,inorder.size()-1,index);
        return root;
    }
};
