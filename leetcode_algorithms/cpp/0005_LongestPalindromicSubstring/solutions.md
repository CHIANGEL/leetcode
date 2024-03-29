# Longest Palindromic Substring

写了三种解法
### 1. 无脑暴力
  
两重循环，外层是subsring的长度，内层是该长度的substring的起始位置，然后对每一个substring都验证其是否是回文串。O(n<sup>3</sup>)时间复杂度，活该TLE。
  
### 2. 优化版本

基本思想就是，若字符串str是回文串，那么只需要验证str左右两边的单个字符是否相等即可得知'a'+str+'b'是否为回文串。

因此每一个回文串都可以由最初的一个字符或两个字符（奇/偶回文）产生。用一层循环遍历字符串s，对2n-1个“初始中心”进行扩充得到2n-1个回文串，比较的出最长的那个。时间复杂度O(n<sup>2</sup>)，成功AC。

### 3. 马拉车算法（Manacher）

还有一种现成的O(n)算法，名为Manacher。

因为回文串可奇可偶，所以Manacher算法首先对初始字符串进行预处理：在每一个字符两边插入'#'，并在开头加上'$'作为标识。E.g. 初始字符串s="abca"，则预处理后的字符串为str="$#a#b#c#a#"。

Manacher算法维护一个一维数组Len[n]、整型变量id和mx。

- id记录上一次操作的位置

- mx记录上一次操作位置的最长回文子串的最右端的位置

- Len[i]代表str（注意不是初始字符串s!）中，以字符str[i]为中心的最长回文子串的最右端到i的长度（包括i）。E.g. 对于str="$#a#b#a#a#"，Len[0]=0, Len[4]=4

具体的更新方法可见：[马拉车算法](https://blog.csdn.net/qq_16554583/article/details/79763296)。基本思路就是按照每次i与mx的大小关系分类，运用回文子串的对称性质。
