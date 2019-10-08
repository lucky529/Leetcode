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
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* cur = head;
		int count = 0;
		while (cur != nullptr && count != k)
		{
			cur = cur->next;
			count++;
		}
		if (count == k)
		{
			cur = reverseKGroup(cur, k);
			while (count-- != 0)
			{
				ListNode* tmp = head->next;
				head->next = cur;
				cur = head;
				head = tmp;
			}
			head = cur;
		}
		return head;
	}
};