# 3Sum Closest

和上一题``15. 3Sum``完全一样的思路：

1. 排序``sort(nums.begin(), nums.end())``

2. 维护与``target``最接近的值``res``，以及两者之间差的绝对值``min_gap``

3. 第一层循环``for (i = 0; i < n - 2; ++i)``，从左向右进行遍历第一个数（三个数中最小的那个）

4. 对``i``向右的区间维护两个数``start = i + 1``，``end = n - 1``，代表三个数中的剩下两个

5. 判断``i > 0 && nums[i] == nums[i - 1]``是否为真

    - 若为真则应该执行``continue``，以避免重复解的出现。E.g. 对输入``-1, -1, 0, 1``，若没有此步骤，结果集就会出现两个``[-1, 0, 1]``
    - 若为假则进行接下来的验证步骤
    - 其实这一步可以省略，因为重复不影响结果，但是可以优化加速

6. 先维护``res``和``min_gap``，然后验证``nums[i] + nums[start] + nums[end]``与``target``的关系

    - 若相等，必然为最优解，直接返回即可！
    
    - 若小于，说明和应该要增加，于是让``start``增加（因为之前排过序了）
    
    - 若大于，说明和应该要减少，于是让``end``减小
    
    - 重复这一步的验证（不用重复更新``res``），直到``start >= end``，即``while(start < end)``
    
7. 注意这里对``start``和``end``的更新要注意跳过一段重复的数字

    - 
      ```
      while(start < end && nums[start] == nums[start + 1])
          start++;
      start++;
      ```
        
            
