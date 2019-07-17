# Symmetric Tree

依旧是递归的思路，另设一个函数``checkSymmetric(TreeNode* left, TreeNode* right)``判断这两个子树是否对称，注意递归的向下应该是比较``left``的左子树和``right``的右子树是否对称、``left``的右子树和``right``的左子树是否对称。
