//16ms 使用队列解决
class Solution {
public:
	string removeOuterParentheses(string S) {
		int flag = 0, cur = 0;
		queue<char> st;
		string ret = "";
		while (cur < S.size())
		{
			while (cur < S.size() && (st.empty() || flag != 0))
			{
				if (S[cur] == '(')
				{
					st.push(S[cur]); flag++; cur++;
				}
				else
				{
					st.push(S[cur]); flag--; cur++;
				}
			}
			st.pop();
			while (!st.empty())
			{
				ret += st.front(); st.pop();
			}
			ret.pop_back();
		}
		return ret;
	}
};