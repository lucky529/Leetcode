//详细解法见博客
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr) return head;
		Node* cur = head;
		while (cur)
		{
			Node* copy = new Node(cur->val);
			copy->next = cur->next;
			cur->next = copy;
			cur = copy->next;
		}
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;
			if (cur->random == nullptr)
			{
				copy->random = nullptr;
			}
			else
			{
				copy->random = cur->random->next;
			}
			cur = copy->next;
		}
		cur = head;
		Node* newhead, *tail;
		newhead = tail = new Node(0);
		while (cur)
		{
			Node* copy = cur->next;
			Node* next = copy->next;

			tail->next = copy;
			tail = copy;
			cur->next = next;

			cur = next;
		}
		return newhead->next;
	}
};