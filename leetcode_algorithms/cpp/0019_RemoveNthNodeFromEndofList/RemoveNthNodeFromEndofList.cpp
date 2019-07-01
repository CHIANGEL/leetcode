/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* point1 = dummy;
		ListNode* point2 = dummy;
		for (int i = 0; i <= n && point1 != NULL; ++i)
			point1 = point1->next;
		while (point1)
		{
			point1 = point1->next;
			point2 = point2->next;
		}
		point2->next = point2->next->next;
		return dummy->next;
	}
};