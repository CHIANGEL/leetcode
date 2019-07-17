# Flip Equivalent Binary Trees

递归解决。首先判断root1和root2是否相同，不同则立刻返回```false```，若```root1 == NULL && root2 == NULL```则立即返回```true```。

否则比价两个root的子树是否Flip Equivalent。有两种子树匹配，一种是不flip左左+右右，另一种是flip后的左右+右左，两种匹配只要有一种为真即可。
