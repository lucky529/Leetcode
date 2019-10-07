//和反转一个单链表基本相似

double_list_node * reverse_double_list(double_list_node * head)
{
	double_list_node* pre = head;
	double_list_node* cur = head->next;
	head->next = nullptr;
	while (cur)
	{
		double_list_node* next = cur->next;
		cur->next = pre;
		pre->pre = cur;
		pre = cur;
		cur = next;
	}
	return pre;
}