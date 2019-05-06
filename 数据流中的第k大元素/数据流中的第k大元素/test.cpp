//76ms ͨ�� 1.˼·�ܼ򵥣�ά��һ��С�ѣ�������ݴ��ڶѶ�Ԫ�ؾ�ɾ���Ѷ�Ԫ�ش�Ԫ����ѷ���ֱ������
class KthLargest {
public:
	KthLargest(int k, vector<int>& nums) {
		top = k;
		for (auto& e : nums)
		{
			add(e);
		}
	}

	int add(int val) {
		if (q.size() < top)
		{
			q.push(val);
		}
		else if (val > q.top())
		{
			q.pop();
			q.push(val);
		}
		return q.top();
	}
private:
	int top;
	priority_queue<int, vector<int>, greater<int>>  q;
};

/**
* Your KthLargest object will be instantiated and called as such:
* KthLargest* obj = new KthLargest(k, nums);
* int param_1 = obj->add(val);
*/