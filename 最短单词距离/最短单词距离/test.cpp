//40msͨ�� 1.ʹ��hash��˼����������1��2��λ�ü�ס 2.ͬʱʹ���ҽ�����˼������С����һ��++
class WordDistance {
public:
	WordDistance(vector<string>& words) {
		for (int i = 0; i < words.size(); i++)
			mp[words[i]].push_back(i);
	}

	int shortest(string word1, string word2) {
		ios::sync_with_stdio(0); cin.tie(NULL);
		int ret = INT_MAX, index1 = 0, index2 = 0;
		while (index1 < mp[word1].size() && index2 < mp[word2].size())
		{
			ret = min(ret, abs(mp[word1][index1] - mp[word2][index2]));
			if (mp[word1][index1] < mp[word2][index2]) {
				index1++;
			}
			else {
				index2++;
			}
		}
		return ret;
	}
private:
	unordered_map<string, vector<int>> mp;
};

/**
* Your WordDistance object will be instantiated and called as such:
* WordDistance* obj = new WordDistance(words);
* int param_1 = obj->shortest(word1,word2);
*/