# Card Flipping Game

当时看完这道题目，一时间没有任何的思路。看了题解Hints，大概了解了思路：

如果一张card的前后两面的数字一样，那么这个数字就不可能是good number，对这些注定不可能是good number的数字建立一个set集合；而对于两面数字不同的card，某面上的数字X若没有在set集合中出现，那X就肯定可以成为一个good number，因为其他card都可以通过翻转使X不出现在fronts面上。

如此，只需要两次遍历即可，一次建立set集合，一次比较得出答案res。
