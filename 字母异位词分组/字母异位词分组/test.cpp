//����ͨ�� 100/101���㷨ʱ�临�Ӷ�Ϊon3
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
//�����Ż� 96ms ͨ�� ������ʹ��26��������ʾ26����ĸ�������ǵĳ˻���Ϊmap��k�����滻����Ĳ��֣�
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