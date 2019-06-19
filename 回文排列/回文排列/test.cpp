//��һ�汩��δͨ�� ԭ����ʵ����ֻ��Ҫ�ж��Ƿ���һ����ַ��Ƿ񹹳ɻ��Ĵ�����
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
//�ڶ���4msͨ�� �ǳ��ɵ��㷨
//1.�������Ǵ���һ��mapͳ��ÿ���ַ����ֵĴ����������Щ�ַ����Թ��ɻ��ģ���ô�ַ��ĳ��ȷ�������ż������
//2.���Ǵ���һ��t������ַ�����ż�����ַ���mid����ų��ֵ��м��ַ���mid�ַ����ȵ���0����1���������һ˵���޷�����
//3.����������ֻ��Ҫ��һ���Ӵ�����ȫ���У�Ȼ�������ȡ������mid�ַ�������
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