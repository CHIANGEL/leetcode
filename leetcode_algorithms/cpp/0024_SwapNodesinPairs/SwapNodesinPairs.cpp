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
	ListNode* swapPairs(ListNode* head) {
		ListNode* p1 = head;
		ListNode* p2 = NULL;
		ListNode* prev = new ListNode(0);
		if (p1 != NULL)
			p2 = p1->next;
		if (p2 != NULL)
			head = p2;
		while (p1 != NULL && p2 != NULL)
		{
			prev->next = p2;
			p1->next = p2->next;
			p2->next = p1;
			prev = p1;
			p1 = p1->next;
			if (p1 != NULL)
				p2 = p1->next;
		}
		return head;
	}
};