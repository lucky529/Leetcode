#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
using namespace std;


//暴力算法 用例35/36 超出时间限制
int main()
{
	string s = "cbaebabacd";
	string p = "abc";
	vector<int> v;
	int arr1[26] = { 0 };
	for (int i = 0; i < p.size(); i++)
	{
		arr1[p[i] - 'a']++;
	}
	for (int i = 0; i < (s.size() - p.size()); i++)
	{
		int arr2[26] = { 0 };
		int flag = 0;
		for (int j = 0; j < p.size(); j++)
		{
			arr2[s[i + j] - 'a']++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (arr1[i] != arr2[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			v.push_back(i);
	}
	cout << endl;
	system("pause");
	return 0;
}

//滑动窗体 48ms 1.每次检测当前窗体中的字符是否与目标字符串匹配 2.下一次将窗体最开始的字符删除，让紧挨着的下一个字符入窗体
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int ls = s.size(), ps = p.size();
		if (ls < ps) return{};

		vector<int> sv(26, 0), pv(26, 0);
		for (int i = 0; i < ps; i++)
		{
			sv[s[i] - 'a']++;
			pv[p[i] - 'a']++;
		}
		vector<int> ret;
		for (int i = ps; i < ls; i++)
		{
			if (sv == pv)
			{
				ret.push_back(i - ps);
			}
			sv[s[i] - 'a']++;
			sv[s[i - ps] - 'a']--;
		}
		if (sv == pv)
			ret.push_back(ls - ps);
		return ret;
	}
};