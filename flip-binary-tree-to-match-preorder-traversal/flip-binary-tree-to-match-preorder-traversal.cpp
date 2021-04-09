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
    void preorder(TreeNode *root,vector<int> &v,int &i,vector<int> &res)
    {
        if(root==NULL)
            return ;
        if(res.size()==1&&res[0]==-1)
            return ;
        if(root->val!=v[i])
        {
            res={-1};
            return ;
        }
        i++;
        if(i<v.size()&&root->left&&v[i]!=root->left->val)
        {
            res.push_back(root->val);
            preorder(root->right,v,i,res);
            preorder(root->left,v,i,res);
        }
        else
        {
            preorder(root->left,v,i,res);
            preorder(root->right,v,i,res);
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
        vector<int> res;
        int i=0;
        preorder(root,v,i,res);
        return res;
    }
};