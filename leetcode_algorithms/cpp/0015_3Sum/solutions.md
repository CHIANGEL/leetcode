# 3Sum

最Naive的算法就是O(n<sup>3</sup>)的遍历算法，先排序，然后两层循环遍历两个数，然后用第三个数用二分法对剩下的区间进行查找是否存在即可。但是会超时。

我用的是O(n<sup>2</sup>)。

1. 排序``sort(nums.begin(), nums.end())``

2. 第一层循环``for (i = 0; i < n - 2; ++i)``，从左向右进行遍历第一个数（三个数中最小的那个）

3. 对``i``向右的区间维护两个数``start = i + 1``，``end = n - 1``，代表三个数中的剩下两个

4. 判断``i > 0 && nums[i] == nums[i - 1]``是否为真

    - 若为真则应该执行``continue``，以避免重复解的出现。E.g. 对输入``-1, -1, 0, 1``，若没有此步骤，结果集就会出现两个``[-1, 0, 1]``
    - 若为假则进行接下来的验证步骤

4. 验证``nums[i] + nums[start] + nums[end]``是否为0

    - 若和为0，则得到一组解，加入res结果数组集，并且让``start``增加且``end``减小
    
    - 若和小于0，说明和应该要增加，于是让``start``增加（因为之前排过序了）
    
    - 若和大于0，说明和应该要减少，于是让``end``减小
    
    - 重复这一步的验证，直到``start >= end``，即``while(start < end)``
    
5. 注意这里对``start``和``end``的更新要注意跳过一段重复的数字

    - 
      ```
      while(start < end && nums[start] == nums[start + 1])
          start++;
      start++;
      ```
        
            
