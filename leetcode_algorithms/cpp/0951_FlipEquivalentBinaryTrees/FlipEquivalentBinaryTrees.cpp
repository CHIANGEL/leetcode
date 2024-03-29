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
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		if (root1 == NULL && root2 == NULL)
			return true;
		if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL) || root1->val != root2->val)
			return false;
		bool LL = (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right));
		bool LR = (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
		return LL || LR;
	}
};