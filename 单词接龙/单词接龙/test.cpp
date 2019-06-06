//�������⽫��ʼ�ַ�����ֹ�ַ����м��ַ���ϵ�г�����ʵ����һ��ͼ�Ĺ�ϵ
//��Ŀ��ת��Ϊ����ͼ����С·�����⣬ֻ��Ҫһ��һ�������Ҿ����ҵ���̵�·��
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