# Invert Binary Tree

还是递归解决

在返回当前``root``前对左子树和右子树分别进行Invert操作

递归的基例为``root == NULL || root->left == NULL && root->right == NULL``
