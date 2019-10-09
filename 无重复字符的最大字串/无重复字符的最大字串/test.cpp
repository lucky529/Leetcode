//使用滑动窗口思想，每次判断当前加入的字符是否已经在最长子串中
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> ss;
		int left = 0, len = 0;
		for (int i = 0; i < s.size(); i++)
		{
			while (ss.find(s[i]) != ss.end())
			{
				ss.erase(s[left]);
				++left;
			}
			ss.insert(s[i]);
			len = max(len, i - left + 1);
		}
		return len;
	}
};