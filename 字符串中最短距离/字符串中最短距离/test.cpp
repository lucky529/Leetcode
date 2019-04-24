//24ms 使用3指针前后指针确定当前C字符区间，然后判断当前位置的字符离哪个C字符更近
class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		vector<int> v;
		int left = 0, right = 0, cur = 0;
		while (right < S.size() && S[right] != C)
		{
			right++;
		}
		while (cur != right)
		{
			v.push_back(right - cur);
			cur++;
		}
		while (right < S.size())
		{
			while (right < S.size() && S[right] != C)
			{
				right++;
			}
			while (cur != right)
			{
				if (cur < S.size() && right == S.size())
				{
					v.push_back(cur - left);
					cur++;
				}
				else
				{
					v.push_back(min(right - cur, cur - left));
					cur++;
				}
			}
			left = right;
			right++;
		}
		while (cur < S.size())
		{
			v.push_back(cur - left);
			cur++;
		}
		return v;
	}
};
//感觉没有3指针效率高不知道为啥20ms通过
class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		vector<int> v(S.size());
		vector<int> index;
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == C)
				index.push_back(i);
		}
		for (int i = 0; i < S.size(); i++)
		{
			int Min = INT_MAX;
			for (auto e : index)
			{
				Min = Min < abs(e - i) ? Min : abs(e - i);
			}
			v[i] = Min;
		}
		return v;
	}
};