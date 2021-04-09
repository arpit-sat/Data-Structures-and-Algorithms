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
    int find_sum(TreeNode *root,int &res)
    {
        if(root==NULL)
            return 0;
        int left=find_sum(root->left,res);
        int right=find_sum(root->right,res);
        res+=abs(left-right);
        return root->val+left+right;
    }
    int findTilt(TreeNode* root) {
        int res=0;
        find_sum(root,res);
        return res;
    }
};