/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
void con(Node* root,Node* prev,int flag)
{
    if(root==nullptr)
        return;
    if(flag==0 && prev->right)
        root->next=prev->right;
    else if(flag==1 && prev->next)
        root->next=prev->next->left;
    con(root->left,root,0);
    con(root->right,root,1);
}
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)
            return root;
        con(root->left,root,0);
        con(root->right,root,1);
        return root;
    }
};
