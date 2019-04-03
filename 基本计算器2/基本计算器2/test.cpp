//����ͨ�� 40/109 ��δ���ǵ����ֿ��ܳ�����λ���ϣ� 1.��׺ת��׺���ʽ 2.����ջ�������㣨�沨�����ʽ��
class Solution {
public:
	int calculate(string s) {
		string str = "";
		stack<char> st;
		stack<int> nst;
		for (auto e : s)
		{
			if (e == ' ') continue;
			else if (e >= '0' && e <= '9') str += e;
			else if (e == '+' || e == '-' || e == '*' || e == '/')
			{
				if (st.empty()) st.push(e);
				else if (e == '+' || e == '-')
				{
					while (!st.empty())
					{
						str += st.top();
						st.pop();
					}
					st.push(e);
				}
				else
				{
					while (!st.empty() && (st.top() == '*' || st.top() == '/'))
					{
						str += st.top();
						st.pop();
					}
					st.push(e);
				}
			}
		}
		while (!st.empty())
		{
			str += st.top();
			st.pop();
		}
		for (auto e : str)
		{
			if (e == '-')
			{
				int right = nst.top();
				nst.pop();
				int left = nst.top();
				nst.pop();
				nst.push(left - right);
			}
			else if (e == '+')
			{
				int right = nst.top();
				nst.pop();
				int left = nst.top();
				nst.pop();
				nst.push(left + right);
			}
			else if (e == '*')
			{
				int right = nst.top();
				nst.pop();
				int left = nst.top();
				nst.pop();
				nst.push(left * right);
			}
			else if (e == '/')
			{
				int right = nst.top();
				nst.pop();
				int left = nst.top();
				nst.pop();
				nst.push(left / right);
			}
			else
			{
				nst.push(e - '0');
			}
		}
		return nst.top();
	}
};

//28ms ͨ�� 1.��¼�ַ����г��ֵ�ÿһ������ 2.��c��¼��һ�����ţ���һ��������+����-ֻ����push���� 3.�������*/֤������
//���в��������Ľ���ڽ���һ�����
class Solution {
public:
	int calculate(string s) {
		int ret = 0, d = 0;
		char c = '+';
		stack<int> nums;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= '0')
			{
				d = d * 10 + (s[i] - '0');
			}
			if ((s[i] < '0' && s[i] != ' ') || i == s.size() - 1)
			{
				if (c == '+')
					nums.push(d);
				else if (c == '-')
					nums.push(-d);
				else if (c == '*' || c == '/')
				{
					int tmp = c == '*' ? nums.top()*d : nums.top() / d;
					nums.pop();
					nums.push(tmp);
				}
				c = s[i];
				d = 0;
			}
		}
		for (; !nums.empty(); nums.pop())
		{
			ret += nums.top();
		}
		return ret;
	}
};