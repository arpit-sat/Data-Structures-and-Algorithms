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
    vector<int> bst(TreeNode *root,int &maxi)
    {
        if(root==NULL)
            return {0,INT_MAX,INT_MIN};
        
        vector<int> left=bst(root->left,maxi);
        vector<int> right=bst(root->right,maxi);
        
        if(left[0]==-1||right[0]==-1||root->val<=left[2]||root->val>=right[1])
            return {-1,0,0};
        int size=1+left[0]+right[0];
        maxi=max(maxi,size);
        return {size,min(root->val,left[1]),max(root->val,right[2])};
    }
    int largestBSTSubtree(TreeNode* root) {
        int maxi=0;
        bst(root,maxi);
        return maxi;
    }
};