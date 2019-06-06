//根据题意将起始字符和终止字符的中间字符关系列出来后实际上一张图的关系
//题目就转化为了找图的最小路径问题，只需要一层一层向外找就能找到最短的路径
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> mp(wordList.begin(), wordList.end());
		unordered_set<string> vis;
		vis.insert(beginWord);
		queue<string> q; q.push(beginWord);
		int count = 1;
		while (!q.empty())
		{
			int size = q.size();
			while (size-- > 0)
			{
				string cur = q.front(); q.pop();
				if (cur == endWord) return count;
				for (int i = 0; i < cur.size(); i++)
				{
					string tmp = cur;
					for (char a = 'a'; a <= 'z'; a++)
					{
						tmp[i] = a;
						if (!mp.count(tmp) || vis.count(tmp)) continue;
						vis.insert(tmp);
						q.push(tmp);
					}
				}
			}
			count++;
		}
		return 0;
	}
};