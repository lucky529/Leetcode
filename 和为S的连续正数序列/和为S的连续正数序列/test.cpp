//双指针思想
//如果当前的num比sum大，那么就左指针加加
//其他情况右指针加加
//当相等时就将数字push到数组中
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		if (sum == 1) return{};
		vector<vector<int>> vv;
		int lo = 1, hi = 2;
		while (hi > lo)
		{
			int cur = (hi + lo)*(hi - lo + 1) / 2;
			if (cur == sum)
			{
				vector<int> v;
				for (int i = lo; i <= hi; i++)
					v.push_back(i);
				vv.push_back(v);
				lo++;
			}
			else if (cur < sum)
				hi++;
			else
				lo++;
		}
		return vv;
	}
};