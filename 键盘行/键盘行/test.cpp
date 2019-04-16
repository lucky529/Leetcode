//8msͨ�� 1.��map��¼�����ϵ������ڵ����� 2.Ȼ�����ÿ�����ĵ����Ƿ���ͬһ���ϼ���
class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		unordered_map<char, int> mp;
		vector<string> strs = { "QWERTYUIOPqwertyuiop", "ASDFGHJKLasdfghjkl", "ZXCVBNMzxcvbnm" }, ret;
		for (int i = 0; i < 3; i++)
		{
			for (auto& e : strs[i])
			{
				mp[e] = i;
			}
		}
		for (auto& e : words)
		{
			if (e.size() < 2)
			{
				ret.push_back(e);
				continue;
			}
			int row = mp[e[0]], index = 0, size = e.size();
			while (index < size)
			{
				if (mp[e[index]] == row)
				{
					index++;
				}
				else
				{
					break;
				}
			}
			if (index == size)
				ret.push_back(e);
		}
		return ret;
	}
};