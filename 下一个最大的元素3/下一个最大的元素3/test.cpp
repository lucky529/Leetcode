//4ms通过 参考大佬 1.找到高位第一个小于低位的2个数字 2.交换这俩个元素 3.对高位之后的数字进行排列
class Solution {
public:
	int nextGreaterElement(int n) {
		string s = to_string(n);
		int high = -1, low = -1;
		for (int i = s.size() - 2; i >= 0; i--)
		{
			for (int j = i; j < s.size(); j++)
			{
				if (s[i] < s[j])
				{
					high = i;
					low = low == -1 ? j : (s[j] > s[low] ? low : j);
				}
			}
			if (high != -1)
			{
				char tmp = s[high];
				s[high] = s[low];
				s[low] = tmp;
				sort(s.begin() + high + 1, s.end());
				double d = atol(s.c_str());//使用atol防止数字太大溢出
				if (d > INT_MAX)
					return -1;
				else
					return d;
			}
		}
		return -1;
	}
};