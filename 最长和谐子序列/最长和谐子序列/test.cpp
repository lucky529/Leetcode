//144ms通过 1.利用map记录每个数字的个数并对数字进行排序 2.判断相邻的两个数字是否等于一 3.如果是跟新当前的max返回值
class Solution {
public:
	int findLHS(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		map<int, int> mp;
		for (auto& e : nums)
		{
			mp[e]++;
		}
		auto pre = mp.begin();
		auto cur = ++mp.begin();
		int max = 0;
		while (cur != mp.end())
		{
			if (cur->first - pre->first == 1)
			{
				max = cur->second + pre->second > max ? cur->second + pre->second : max;
			}
			cur++; pre++;
		}
		return max;
	}
};