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
	int maxDepth(TreeNode* root) {
		return measureDepth(root, 0);
	}

private:
	int measureDepth(TreeNode* root, int depth) {
		if (root == NULL)
			return depth;
		return max(measureDepth(root->left, depth + 1), measureDepth(root->right, depth + 1));
	}
};