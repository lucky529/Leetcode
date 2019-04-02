//用例通过 100/101，算法时间复杂度为on3
class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		int arr1[26] = { 0 };
		for (int i = 0; i < s.size(); i++) arr1[s[i] - 'a']++;
		for (int i = 0; i < t.size(); i++) arr1[t[i] - 'a']--;
		for (int i = 0; i < 26; i++) {
			if (arr1[i] < 0)
				return false;
		}
		return true;
	}
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> vv(1, vector<string>());
		vector<string> v;
		int index = 0;
		while (strs.size() != 0)
		{
			vv[index].push_back(strs[0]);
			for (int i = 1; i < strs.size(); i++)
			{
				if (isAnagram(vv[index][0], strs[i]))
				{
					vv[index].push_back(strs[i]);
				}
				else
				{
					v.push_back(strs[i]);
				}
			}
			vv.push_back(vector<string>());
			index++;
			strs.swap(v); v.clear();
		}
		vv.pop_back();
		return vv;
	}
};
//代码优化 96ms 通过 （可以使用26个质数表示26个字母，用他们的乘积作为map的k，来替换排序的部分）
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		if (strs.size() <= 0) return{};
		vector<vector<string>> vv;
		unordered_map<string, vector<string>> mp;
		for (auto s : strs)
		{
			string str = s;
			sort(str.begin(), str.end());
			mp[str].push_back(s);
		}
		for (auto e : mp)
		{
			vv.push_back(e.second);
		}
		return vv;
	}
};