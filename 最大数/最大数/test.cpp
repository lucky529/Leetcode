//75msͨ�� 1.�ǳ���Ȥ��һ���⣬����ǰһ���ַ��Ӻ�һ���ַ����һ���ַ���ǰһ���ַ��Ƚϴ�С���������һ�����򼴿�
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