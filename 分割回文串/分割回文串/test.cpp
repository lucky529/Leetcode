//102ms通过 1.使用递归回溯 2.控制每次分割的字符大小
class Solution {
public:
	vector<vector<string>> vv;
	vector<string> v;
	bool checkstr(string s)
	{
		string tmp(s);
		reverse(tmp.begin(), tmp.end());
		if (s == tmp) return true;
		else return false;
	}
	void strpart(string s, int start, int end)
	{
		if (start > end)
		{
			vv.push_back(v);
			return;
		}
		for (int i = 1; i <= end - start + 1; i++)
		{
			if (checkstr(s.substr(start, i)))
			{
				v.push_back(s.substr(start, i));
				strpart(s, start + i, end);
				v.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s) {
		strpart(s, 0, s.size() - 1);
		return vv;
	}
};