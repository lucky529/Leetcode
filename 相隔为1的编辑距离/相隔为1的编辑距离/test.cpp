//删除从某种意义上来讲就是跳过这个字符 所以我们只需要判断跳过当前的字符是否成立
class Solution {
public:
	bool checkstr(string s, int cur1, string t, int cur2)
	{
		string s1 = s.substr(cur1);
		string s2 = t.substr(cur2);
		if (s1 == "" && s2 == "") return false;
		if (s1 == s2)
			return true;
		else
			return false;
	}
	bool checkss(string s, int cur1, string t, int cur2)
	{
		s[cur1] = t[cur2];
		if (s == t) return true;
		else return false;
	}
	bool isOneEditDistance(string s, string t) {
		int ns = s.size(), nt = t.size();
		if (s == t)return false;
		if (abs(ns - nt) > 1) return false;
		int cur1 = 0, cur2 = 0;
		while (cur1 < ns && cur2 < nt)
		{
			if (s[cur1] != t[cur2])
				return checkstr(s, cur1, t, cur2 + 1) || checkstr(s, cur1 + 1, t, cur2 + 1)
				|| checkss(s, cur1, t, cur2) || checkstr(s, cur1 + 1, t, cur2);

			cur1++; cur2++;
		}
		return true;
	}
};