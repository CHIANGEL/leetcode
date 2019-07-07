# 4Sum

参照3Sum的解法，数组排序后，先确定前两个数``nums[i]``和``nums[j]``，这里要加入一些剪枝和特判：

- 若``i != 0 && nums[i] == num[i - 1]``，则直接``continue``，否则可能出现重复结果。对``nums[j]``同理

- 若``4 * nums[i] > target``，则直接``break``，返回结果集。因为数组从小到大排序，若目前的最小可能组合都比``target``大了，那接下来的所有搜索都是没有意义的，肯定比``target``大。

- 若``nums[i] + nums[nums.size() - 3] + nums[nums.size() - 2] + nums[nums.size() - 1] < target``，则直接``continue``。若固定第一个数``nums[i]``后的最大可能组合都比``target``小，那么当前对第一个数``nums[i]``的搜索就没有意义了。

在确定了前两个数后，对剩下的两个数，采用3Sum中的方法，维护``left``和``right``两个指针，从剩下区间的头尾两端向中间推进即可。
