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
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == NULL)
			return NULL;
		if (root->val == val)
			return root;
		return val > root->val ? searchBST(root->right, val) : searchBST(root->left, val);
	}
};