/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root)
			return checkSymmetric(root->left, root->right);
		return true;
	}

private:
	bool checkSymmetric(TreeNode* left, TreeNode* right) {
		if (!left && !right)
			return true;
		else if (!left || !right)
			return false;
		if (left->val == right->val)
			return checkSymmetric(left->left, right->right) &&
			checkSymmetric(left->right, right->left);
		return false;
	}
};