//560ms 递归，写的太辣鸡了，居然过了
class Solution {
public:
	vector<string> v;
	void _letterCasePermutation(vector<string>& v, int cur, string& S)
	{
		if (S[cur] != '\0')
		{
			if (S[cur] >= '0' && S[cur] <= '9')
			{
				if (find(v.begin(), v.end(), S) == v.end())
				{
					v.push_back(S);
				}
				_letterCasePermutation(v, cur + 1, S);
			}
			else
			{
				if (S[cur] >= 'a' && S[cur] <= 'z')
				{
					if (find(v.begin(), v.end(), S) == v.end())
					{
						v.push_back(S);
					}
					_letterCasePermutation(v, cur + 1, S);
					S[cur] = S[cur] - 32;
					if (find(v.begin(), v.end(), S) == v.end())
					{
						v.push_back(S);
					}
					_letterCasePermutation(v, cur + 1, S);
				}
				else
				{
					if (find(v.begin(), v.end(), S) == v.end())
					{
						v.push_back(S);
					}
					_letterCasePermutation(v, cur + 1, S);
					S[cur] = S[cur] + 32;
					if (find(v.begin(), v.end(), S) == v.end())
					{
						v.push_back(S);
					}
					_letterCasePermutation(v, cur + 1, S);
				}
			}
		}
		return;
	}
	vector<string> letterCasePermutation(string S) {
		int cur = 0;
		_letterCasePermutation(v, cur, S);
		return v;
	}
};

//优化版本，题目好像默认字符不会重复
class Solution {
public:
	vector<string> letterCasePermutation(string S) {
		vector<string> res;
		backTracking(0, res, S);
		return res;
	}
	void backTracking(int start, vector<string>& res, string s){
		if (start == s.size()){
			res.push_back(s);
			return;
		}

		if (s[start] >= '0'&&s[start] <= '9'){
			backTracking(start + 1, res, s);
			return;
		}

		s[start] = tolower(s[start]);
		backTracking(start + 1, res, s);

		s[start] = toupper(s[start]);
		backTracking(start + 1, res, s);
	}
};