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
	Solution() { sum = 0; cur = 0; }
	int sumNumbers(TreeNode* root) {
		if (root == NULL)
			return sum;
		(cur *= 10) += (root->val);
		if (root->left == NULL && root->right == NULL)
		{
			sum += cur;
			cur /= 10;
			return sum;
		}
		if (root->left)
			sumNumbers(root->left);
		if (root->right)
			sumNumbers(root->right);
		cur /= 10;
		return sum;
	}
private:
	int sum;
	int cur;
};