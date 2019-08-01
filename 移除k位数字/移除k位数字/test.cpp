//从左向右移除第一个大于后一个数字的数
class Solution {
public:
	string removeKdigits(string num, int k) {
		if (num.size() <= k) return "0";
		vector<char> st;
		int top = 0;
		for (int i = 0; i < num.size(); i++)
		{
			while (st.size() > 0 && num[i] < st.back() && k > 0)
			{
				k--;
				st.pop_back();
			}
			if (st.size() == 0 && num[i] == '0') continue;
			st.push_back(num[i]);
		}
		string ret = "";
		for (auto& e : st)
			ret += e;
		while (k--) ret.pop_back();
		return ret.size() == 0 ? "0" : ret;
	}
};