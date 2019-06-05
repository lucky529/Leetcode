/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//有点像交换俩个节点的控制点，然后交换一拉就完成了反转
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode* L = new ListNode(-1);
		L->next = head;
		ListNode *p = head->next, *t = head, *q = L;
		int times = n - m;
		while (--m)
		{
			q = q->next;
			t = t->next;
			p = p->next;
		}
		while (times--)
		{
			t->next = p->next;
			p->next = q->next;
			q->next = p;
			p = t->next;
		}
		return L->next;
	}
};