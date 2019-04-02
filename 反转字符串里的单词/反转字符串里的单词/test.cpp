// 76ms ͨ�� 1.��ȡ�����е��ַ��� 2.ѹ��ջ�� 3.�����ַ���
class Solution {
public:
	string reverseWords(string s) {
		stack<string> st;
		int cur = 0, pre = 0, count = 0;
		while (s[cur] == ' ') cur++;
		while (cur < s.size())
		{
			pre = cur;
			while (cur < s.size() && s[cur] != ' ')
			{
				cur++; count++;
			}
			string tmp = s.substr(pre, count);
			st.push(tmp);
			while (cur < s.size() && s[cur] == ' ')
			{
				cur++;
			}
			count = 0;
		}
		string ret = "";
		while (!st.empty())
		{
			ret = ret + (st.top() + " ");
			st.pop();
		}
		ret.pop_back();
		return ret;
	}
};
//76ms ����istringstream is(s)������Ƴ��ո� �о����������⣬��Ӧ��76ms��ô��
class Solution {
public:
	string reverseWords(string s) {
		string ans = "";
		if (!s.empty())
		{
			string word;
			istringstream is(s);
			while (is >> word)
			{
				ans = word + " " + ans;
			}
		}
		ans.pop_back();     //ȥ��ĩβ�ո�
		return ans;
	}
};