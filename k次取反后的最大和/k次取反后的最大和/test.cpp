//28ms通过 使用堆反而效率没有排序高
class Solution {
public:
	int largestSumAfterKNegations(vector<int>& A, int k) {
		int ret = 0;
		priority_queue<int, vector<int>, greater<int>> q(A.begin(), A.end());
		while (q.top() < 0 && k > 0)
		{
			int top = q.top(); q.pop();
			q.push(abs(top));
			k--;
		}
		if (k % 2 != 0)
		{
			ret += -(q.top()); q.pop();
		}
		while (!q.empty())
		{
			ret += q.top(); q.pop();
		}
		return ret;
	}
};