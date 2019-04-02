// 76ms 通过 1.提取句子中的字符串 2.压入栈中 3.链接字符串
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
//76ms 利用istringstream is(s)巧妙的移除空格 感觉测试有问题，不应该76ms这么慢
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
		ans.pop_back();     //去掉末尾空格
		return ans;
	}
};