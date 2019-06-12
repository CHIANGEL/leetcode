# Prime Number of Set Bits in Binary Representation

很简单的一道题目，int整型最多只有32位，因此只需要做32以内的素数判断，果断打表！

另一点是关于如何计算set bits，我一开始想通过打表找规律来高效的统计setbits（毕竟是连续的数字，可能有规律就不用一个一个count了），但是没有找到。因此还是很老实地写了一个setBits(int n)的函数来挨个统计，速度也是很快的。

但是关于如何统计二进制中1的个数，我用的并非O(1)算法（可以认为是O(32)），但在网上翻到了一种O(1)算法：

```
int setBits(int x){  
    x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);  
    x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);  
    x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);  
    x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);  
    x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);  
    return x;  
} 
```
但目前还没有搞懂为什么，只能说位运算打法好呀。
