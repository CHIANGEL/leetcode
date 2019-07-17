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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> stack;
		TreeNode* op = root;
		while (op || !stack.empty())
		{
			while (op)
			{
				stack.push(op);
				op = op->left;
			}
			op = stack.top();
			stack.pop();
			res.push_back(op->val);
			op = op->right;
		}
		return res;
	}
};