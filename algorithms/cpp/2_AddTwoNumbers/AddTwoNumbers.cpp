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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* sum = new ListNode(0);
		ListNode* previous = NULL;
		ListNode* head = sum;
		while (l1 != NULL || l2 != NULL)
		{
			int addend1 = l1 == NULL ? 0 : l1->val;
			int addend2 = l2 == NULL ? 0 : l2->val;
			sum->val += addend1 + addend2;
			sum->next = new ListNode(sum->val / 10);
			sum->val %= 10;
			previous = sum;
			sum = sum->next;
			l1 = l1 == NULL ? l1 : l1->next;
			l2 = l2 == NULL ? l2 : l2->next;
		}
		if (sum->val == 0)
		{
			sum = previous;
			delete sum->next;
			sum->next = NULL;
		}
		return head;
	}
};