//28msͨ�� 1.����ַ�����ע��ĩβ��..���ַ������������/�ᱨ�� 2.��ջ���� 3.�����ַ��������ж��Ƿ�ɾ��β����/��
class Solution {
public:
	string simplifyPath(string path) {
		stack<string> st;
		vector<string> v;
		path += "/";//��ֹĩβ��..ʱ����ַ�������
		int pre = 0, cur = 0, count = 1;
		//�����Ŀ�ַ���
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
		//�������ַ�������ջ��
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
		//��ջ���ַ����ó�
		string ret = "";
		while (!st.empty())
		{
			ret = st.top() + ret;
			st.pop();
		}
		//�ж��Ƿ���Ҫɾ��β����/��
		if (ret.size() != 1 && ret[ret.size() - 1] == '/')
			ret.pop_back();
		return ret;
	}
};