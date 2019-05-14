//168msͨ�� 1.����set��¼ÿһ�����ӵĵ��� 2.�жϵ�ǰ���ʼ�ȥһ���ִ��Ƿ����set��
class Solution {
public:
	string longestWord(vector<string>& words) {
		sort(words.begin(), words.end());
		set<string> s;
		string ret = "";
		for (auto str : words)
		{
			if (str.size() == 1 || s.find(str.substr(0, str.size() - 1)) != s.end())
			{

				ret = str.size() > ret.size() ? str : ret;
				s.insert(str);
			}
		}
		return ret;
	}
};