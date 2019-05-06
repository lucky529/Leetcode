//76ms 通过 1.思路很简单，维护一个小堆，如果数据大于堆顶元素就删除堆顶元素此元素入堆否则直接跳过
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