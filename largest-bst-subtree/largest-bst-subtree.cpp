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
class Data {
	public:
	bool isBST;
	int maxVal, minVal;
	int size;
	Data(bool isBST, int maxVal, int minVal,  int size) {
		this->isBST = isBST;
		this->size = size;
		this->maxVal = maxVal;
		this->minVal = minVal;
}
};


Data helper(TreeNode* root, int &maxSize) {
	// For NULL
	if (root == NULL) {
		Data temp(true, INT_MIN, INT_MAX, 0);
		return temp;
}

	// Leaf Node


Data left = helper(root->left, maxSize);
Data right = helper(root->right, maxSize);

bool isBST = left.isBST and right.isBST and left.maxVal < root->val and root->val < right.minVal;


int curSize = 1 + left.size + right.size;

if (isBST) {
	maxSize = max(maxSize, curSize);
}

int curMaxVal = max(root->val, right.maxVal);
int curMinVal = min(root->val, left.minVal);

Data temp(isBST, curMaxVal, curMinVal, curSize);
return temp;

	

}


int largestBSTSubtree(TreeNode* root) {
if (root == NULL) {
return 0;
}
int maxSize = 0;
Data ans = helper(root, maxSize);
return maxSize;
 }

};