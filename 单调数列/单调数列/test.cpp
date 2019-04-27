//使用flag标记状态
class Solution {
public:
	int cmp(int x, int y) {
		if (x == y)
			return 0;
		else if (x > y)
			return 1;
		else
			return -1;
	}
	bool isMonotonic(vector<int>& A) {
		int flag = 0;
		for (int i = 0; i < A.size() - 1; i++) {
			int c = cmp(A[i], A[i + 1]);
			if (c != 0) {
				if (c != flag && flag != 0)
					return false;
				flag = c;
			}
		}
		return true;
	}
};
//前后指针
class Solution {
public:
	bool isMonotonic(vector<int>& A) {
		if (A.size() == 1 || A.size() == 2) return true;
		int pre = 0, cur = 1;
		while (cur < A.size() && A[pre] == A[cur])
		{
			pre = cur; cur++;
		}
		if (cur < A.size() && A[pre] < A[cur])
		{
			for (int i = cur; i < A.size(); i++)
			{
				if (A[i] < A[i - 1])
					return false;
			}
		}
		else if (cur < A.size() && A[pre] > A[cur])
		{
			for (int i = cur; i < A.size(); i++)
			{
				if (A[i] > A[i - 1])
					return false;
			}
		}
		return true;
	}
};