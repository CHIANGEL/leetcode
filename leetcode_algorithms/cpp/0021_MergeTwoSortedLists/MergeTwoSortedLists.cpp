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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		else if (l2 == NULL)
			return l1;

		ListNode* res;
		if (l1->val < l2->val)
		{
			res = l1;
			l1 = l1->next;
		}
		else
		{
			res = l2;
			l2 = l2->next;
		}

		ListNode* op = res;
		do
		{
			if (l1 == NULL)
			{
				op->next = l2;
				return res;
			}
			else if (l2 == NULL)
			{
				op->next = l1;
				return res;
			}
			if (l1->val < l2->val)
			{
				op->next = l1;
				op = op->next;
				l1 = l1->next;
			}
			else
			{
				op->next = l2;
				op = op->next;
				l2 = l2->next;
			}
		} while (l1 != NULL || l2 != NULL);
		return res;
	}
};