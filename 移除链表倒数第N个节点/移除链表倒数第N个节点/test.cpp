class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (n == 0) return head;
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* pre = nullptr;
		while (n--)
		{
			if (fast == nullptr)
				return nullptr;
			fast = fast->next;
		}
		while (fast)
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next;
		}
		if (pre == nullptr)
			return head->next;
		else
		{
			pre->next = slow->next;
		}
		return head;
	}
};