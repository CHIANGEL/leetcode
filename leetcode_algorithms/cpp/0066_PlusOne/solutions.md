# Letter Combinations of a Phone Number

一道很常规的DFS搜索，需要另外定义：

1. ``dfs(string digits, string str)``函数

    - ``digits``代表到了这一层深搜还剩余的数字串
    - ``str``代表到了这一层深搜节点 所组合出来的结果字符串
    
2. ``vector< vector<char> >``哈希映射

    - 代表2~9分别对应的字符。
