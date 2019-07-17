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
	TreeNode* bstToGst(TreeNode* root) {
		rightTraverse(root, 0);
		return root;
	}

private:
	int rightTraverse(TreeNode* node, int sum) {
		if (node == NULL)
			return sum;
		node->val += rightTraverse(node->right, sum);
		return rightTraverse(node->left, node->val);
	}
};