//144msͨ�� 1.����map��¼ÿ�����ֵĸ����������ֽ������� 2.�ж����ڵ����������Ƿ����һ 3.����Ǹ��µ�ǰ��max����ֵ
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