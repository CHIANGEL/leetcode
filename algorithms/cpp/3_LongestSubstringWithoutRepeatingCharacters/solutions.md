# Longest Substring Without Repeating Characters

## 初始版本

在初始版本里，我维护一个区间[start, end]，用map将每一个字符映射到s中的索引位置，然后用另一个变量i去遍历字符串s。

若s[i]没有在map中出现过，那就加入map，end = end + 1。

若s[i]在map中出现过，那就需要挪动start（在这之前要更新result = max(result, end - start)），并且将[start, charmap[s[i]]]区间中的其他字符从map中删去。

时间复杂度比O(n)略多。

## 优化版本

在题解中发现一个概念叫做sliding windows，即维护一个[start, end)区间即可，和初始版本里的[start, end]很像，但是不需要额外的i。

更重要的，初始版本里的将其他字符从charmap中插入是不必要的，可以在更新start = max(start, charmap[s[end]] + 1)即可，这样就真正实现了O(n)的时间复杂度。
