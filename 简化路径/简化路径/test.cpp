//28ms通过 1.拆解字符串，注意末尾是..的字符串如果不加上/会报错 2.入栈操作 3.链接字符串并且判断是否删除尾部“/”
class Solution {
public:
	string simplifyPath(string path) {
		stack<string> st;
		vector<string> v;
		path += "/";//防止末尾是..时拆解字符串报错
		int pre = 0, cur = 0, count = 1;
		//拆解题目字符串
		while (cur < path.size())
		{
			while (path[cur] != '/')
			{
				cur++; count++;
			}
			string tmp = path.substr(pre, count);
			v.push_back(tmp);
			pre = ++cur;
			count = 1;
		}
		//将拆解的字符串放入栈中
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == "/")
			{
				if (st.empty()) st.push(v[i]);
				else continue;
			}
			else if (v[i] == "../")
			{
				if (st.size() == 1) continue;
				else st.pop();
			}
			else if (v[i] == "./")
			{
				continue;
			}
			else
			{
				st.push(v[i]);
			}
		}
		//将栈中字符串拿出
		string ret = "";
		while (!st.empty())
		{
			ret = st.top() + ret;
			st.pop();
		}
		//判断是否需要删除尾部“/”
		if (ret.size() != 1 && ret[ret.size() - 1] == '/')
			ret.pop_back();
		return ret;
	}
};