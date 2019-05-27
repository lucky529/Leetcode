//12ms通过 1.使用map映射单词序列中出现的次数 2.找到单词序列中第一个不相同的字符比较大小 3.对前缀相同的单词进行特殊处理
class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		map<char, int> mp;
		for (int i = 0; i <= 25; i++) {
			mp[order[i]] = i;
		}
		for (int i = 1; i < words.size(); i++) {
			int pre = 0, cur = 0;
			while (pre < words[i - 1].size() && cur < words[i].size()) {
				while (mp[words[i - 1][pre]] == mp[words[i][cur]]) {
					pre++; cur++;
				}
				if (mp[words[i - 1][pre]] > mp[words[i][cur]] ||
					(cur == words[i].size() && pre < words[i - 1].size()))
					return false;
				else
					break;
			}
		}
		return true;
	}
};