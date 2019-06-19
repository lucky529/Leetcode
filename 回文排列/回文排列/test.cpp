//第一版暴搜未通过 原因是实际上只需要判断是否有一半的字符是否构成回文串即可
class Solution {
public:
	set<string> ss;
	bool check(string& s)
	{
		int start = 0, end = s.size() - 1;
		while (start < end)
		{
			if (s[start] != s[end])
				return false;
			start++; end--;
		}
		return true;
	}
	void _generatePalindromes(string& s, int index)
	{
		if (index == s.size() && check(s))
		{
			ss.insert(s);
		}
		for (int i = index; i < s.size(); i++)
		{
			swap(s[index], s[i]);
			_generatePalindromes(s, index + 1);
			swap(s[index], s[i]);
		}
	}
	vector<string> generatePalindromes(string s) {
		_generatePalindromes(s, 0);
		return vector<string>(ss.begin(), ss.end());
	}
};
//第二版4ms通过 非常巧的算法
//1.首先我们创建一个map统计每个字符出现的次数，如果这些字符可以构成回文，那么字符的长度分奇数和偶数两种
//2.我们创建一个t串存放字符出现偶数的字符，mid串存放出现的中间字符，mid字符长度等于0或者1，如果大于一说明无法构造
//3.接下来我们只需要对一半子串进行全排列，然后将这个串取反加上mid字符串即可
class Solution {
public:
	vector<string> generatePalindromes(string s) {
		unordered_set<string> res;
		unordered_map<char, int> m;
		string t = "", mid = "";
		for (auto a : s) ++m[a];
		for (auto it : m) {
			if (it.second % 2 == 1) mid += it.first;
			t += string(it.second / 2, it.first);
			if (mid.size() > 1) return{};
		}
		permute(t, 0, mid, res);
		return vector<string>(res.begin(), res.end());
	}
	void permute(string &t, int start, string mid, unordered_set<string> &res) {
		if (start >= t.size()) {
			res.insert(t + mid + string(t.rbegin(), t.rend()));
		}
		for (int i = start; i < t.size(); ++i) {
			if (i != start && t[i] == t[start]) continue;
			swap(t[i], t[start]);
			permute(t, start + 1, mid, res);
			swap(t[i], t[start]);
		}
	}
};