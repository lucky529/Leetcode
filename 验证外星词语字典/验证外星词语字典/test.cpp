//12msͨ�� 1.ʹ��mapӳ�䵥�������г��ֵĴ��� 2.�ҵ����������е�һ������ͬ���ַ��Ƚϴ�С 3.��ǰ׺��ͬ�ĵ��ʽ������⴦��
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