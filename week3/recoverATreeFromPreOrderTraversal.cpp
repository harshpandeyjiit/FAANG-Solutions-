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
pair<int,int> getInt(string s,int pos)
{
    int j=pos;
    while(j<s.size() && isdigit(s[j]))
        j++;
    j--;
    string num=s.substr(pos,j-pos+1);
    int a=stoi(num);
    return {a,j+1};

}
TreeNode* createF(string& s,int& index,int depth)
{
    int level=0;
    while(index + level<s.size() && s[index + level]=='-')
        level++;
    if(level!=depth)
        return NULL;
    index+=level;
    pair<int,int> num = getInt(s,index);
    TreeNode* root=new TreeNode(num.first);
    index=num.second;
    root->left=createF(s,index,depth+1);
    root->right=createF(s,index,depth+1);
    return root;
}
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        if(s.size()==0)
            return NULL;
        int index=0;
        TreeNode* root=createF(s,index,0);
        return root;
    }
};
