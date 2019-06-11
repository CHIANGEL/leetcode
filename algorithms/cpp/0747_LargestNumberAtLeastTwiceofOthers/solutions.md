# Largest Number At Least Twice of Others

过于简单，一次遍历，维护最大数和次大数以及最大数的index即可。

但是在比较最大数fir_max和次大数sec_max时一定要注意溢出问题！一下比较方式都可能会在边界测试中发生溢出：

- fir_max / sec_max >= 2
- fir_max >= 2 * sec_max
- fir_max - sec_max >= sec_max

我采用的一种正确比较方式是：
- sec_max < INT_MAX / 2 || fir_max >= 2 * sec_max
