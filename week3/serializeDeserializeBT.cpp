/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "[none]";
        string s="[";
        queue<TreeNode* >q;
        q.push(root);
        string num = to_string(root->val);
        s+=num;
        s+=",";
        while(q.empty()==false)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
                s+=to_string(temp->left->val);
                s+=",";
            }
            else if(!temp->left)
                s+="none,";
            if(temp->right)
            {
                q.push(temp->right);
                s+=to_string(temp->right->val);
                s+=",";
            }
            else if(!temp->right)
                s+="none,";

        }
        s.pop_back();
        s+="]";
        return s;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.size();
        vector<string>v;
        int i=1;
        while(i<n)
        {
            if(data[i]=='n')
            {
                v.push_back("none");
                i+=4;
            }
            else if(data[i]==',' || data[i]=='\]')
            {
                i++;
            }
            else
            {
                int neg=0;
                if(data[i]=='-')
                {
                    neg=1;
                    i++;
                }
                int j=i;
                while(j<n && isdigit(data[j]))j++;
                j--;
                string num=data.substr(i,j-i+1);
                if(neg==1)
                    num="-"+num;
                v.push_back(num);
                i=j+1;
            }
        }
        if(v[0]=="none")
                return NULL;
        int index=1;
        int a=stoi(v[0]);
        TreeNode* root=new TreeNode(a);
        queue<TreeNode* >q;
        q.push(root);
        while(index<v.size() && q.empty()==false)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(v[index]!="none")
            {
                int a=stoi(v[index]);
                TreeNode* newNode=new TreeNode(a);
                temp->left=newNode;
                q.push(newNode);
            }
            index++;
            if(v[index]!="none")
            {
                int a=stoi(v[index]);
                TreeNode* newNode=new TreeNode(a);
                temp->right=newNode;
                q.push(newNode);
            }
            index++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
