# Two Sum

显然，暴力遍历，时间复杂度O(n<sup>2</sup>)，空间复杂度O(1)。

也可以用空间换时间，对每一个nums[i]到i建立hash map，接着一次遍历，每次通过O(1)的hash查找确定是否存在与之互补的数。
