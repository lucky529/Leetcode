//75ms通过 1.非常有趣的一道题，利用前一个字符加后一个字符与后一个字符加前一个字符比较大小对数组进行一遍排序即可
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		if (nums.size() == 0) return "0";
		sort(nums.begin(), nums.end(), [&](const int& q, const int& p)
		{
			string s1 = to_string(q);
			string s2 = to_string(p);
			return s1 + s2 > s2 + s1;
		});
		string ret = "";
		for (auto& e : nums)
			ret += to_string(e);

		if (ret[0] == '0') return "0";
		return ret;
	}
};