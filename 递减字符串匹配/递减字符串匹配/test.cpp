//66ms通过 遇到I就取最小的，遇到D就取最大的，有点回文的思想
class Solution {
public:
	vector<int> diStringMatch(string S) {
		vector<int> flag(S.size() + 1);
		vector<int> v;
		for (int i = 0; i <= S.size(); i++)
		{
			flag[i] = i;
		}
		int start = 0, end = S.size();
		for (auto& e : S)
		{
			if (e == 'I')
			{
				v.push_back(flag[start++]);
			}
			else
			{
				v.push_back(flag[end--]);
			}
		}
		v.push_back(start);
		return v;
	}
};