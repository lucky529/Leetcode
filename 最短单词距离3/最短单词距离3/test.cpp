//33msͨ�� ��֮ǰ��ͬ����������жϵ�ʱ���������������ͬ���Ǳ��뱣֤���ǵ��±겻��ͬһ��
class Solution {
public:
	unordered_map<string, vector<int>> mp;
	int shortestWordDistance(vector<string>& words, string word1, string word2) {
		ios::sync_with_stdio(0); cin.tie(NULL);
		for (int i = 0; i < words.size(); i++)
			mp[words[i]].push_back(i);

		int ret = INT_MAX, index1 = 0, index2 = 0;
		while (index1 < mp[word1].size() && index2 < mp[word2].size())
		{
			if (word1 == word2)
			{
				if (index1 != index2)
					ret = min(ret, abs(mp[word1][index1] - mp[word2][index2]));
			}
			else
				ret = min(ret, abs(mp[word1][index1] - mp[word2][index2]));
			if (mp[word1][index1] <= mp[word2][index2]) {
				index1++;
			}
			else {
				index2++;
			}
		}
		return ret;
	}
};