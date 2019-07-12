//40ms通过 1.使用hash的思想来讲单词1和2的位置记住 2.同时使用找交集的思想来让小的那一个++
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