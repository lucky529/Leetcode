//168ms通过 1.利用set记录每一个增加的单词 2.判断当前单词减去一的字串是否存在set中
class Solution {
public:
	string longestWord(vector<string>& words) {
		sort(words.begin(), words.end());
		set<string> s;
		string ret = "";
		for (auto str : words)
		{
			if (str.size() == 1 || s.find(str.substr(0, str.size() - 1)) != s.end())
			{

				ret = str.size() > ret.size() ? str : ret;
				s.insert(str);
			}
		}
		return ret;
	}
};