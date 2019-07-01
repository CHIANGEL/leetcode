# Remove Nth Node From End of List

两次遍历的算法很简单，就是先一次遍历取到列表尾部，然后向前数n个即可。重点是如何构思一次遍历完成的算法！

维护两个指针``p1``和``p2``，一开始两个指针都指向列表的头，然后先让``p1``向尾移动n位，这样``p1``和``p2``就有了n位的差距，然后再让两个指针同时向尾部移动直到``p1``指向尾部，则此时滞后于``p1``n位的``p2``就刚好指向要被删除的倒数第n个数。

在具体的算法实现上，很可能一开始写出来的代码是这样的：

```
ListNode* buggy_removeNthFromEnd(ListNode* head, int n) {
   ListNode* point1 = head;
   ListNode* point2 = head;
   int i = 0;
   for (int i = 0; i <= n && point1 != NULL; ++i)
     point1 = point1->next;
   while (point1)
   {
     point1 = point1->next;
     point2 = point2->next;
   }
   point2->next = point2->next->next;
   return head;
}
```

这样的实现方法不能处理``要删除的是head的情况``！但是增加特判会很麻烦，因此可以考虑添加一个超前指针``dummy``，令其指向``head``指针，而``p1``和``p2``指针都指向``dummy``即可，这样子头指针也一样可以删去，返回值为``dummy->next``。
