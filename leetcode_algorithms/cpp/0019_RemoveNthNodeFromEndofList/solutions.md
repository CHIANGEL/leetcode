# Container With Most Water

提供了两种解法

### 暴力解法

两层循环遍历，把每一个可能的container都试一次，复杂度为O(n<sup>2</sup)，勉强没有TLE，也AC了！
  
### 优化算法

维护两个指针``start``和``end``，分别代表container的左右两边。同时维护``res``来保存最大容水量。

初始时，``start``和``end``分别指向数组``nums``的左右两端，之后不断重复以下步骤直到``start>=end``:

1. 以``start``和``end``所在位置构造一个container并更新``res``

2. 比较``nums[start]``与``nums[end]``的大小, 将数值小的那一边的指针向中间移动一格，即``++start``或``--end``

这么更新指针的核心思想在于：container的容量由底边和高决定，底边即``start-end``、高则是``nums[start]``和nums[end]``的最小值。因此当把指针往里面移动的时候，底边一定是减少的，我们需要在“高”上面下功夫，因此必须把“拖后腿”的小数值的指针移动以期望得到一个更好的容量。
