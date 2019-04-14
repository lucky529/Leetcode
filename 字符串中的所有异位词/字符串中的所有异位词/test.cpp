#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
using namespace std;


//�����㷨 ����35/36 ����ʱ������
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

//�������� 48ms 1.ÿ�μ�⵱ǰ�����е��ַ��Ƿ���Ŀ���ַ���ƥ�� 2.��һ�ν������ʼ���ַ�ɾ�����ý����ŵ���һ���ַ��봰��
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