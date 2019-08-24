//1.建立字典的映射关系，字母之间的距离的数组为K，字符串数组为value 2.str[i+1]-str[i]-26再取模是防止出现循环一圈的问题
class Solution {
public:
	vector<vector<string>> groupStrings(vector<string>& strings) {
		map<vector<int>, vector<string>> mp;
		for (auto& str : strings) {
			vector<int> tmp;
			for (int i = 0; i < str.size() - 1; i++) {
				tmp.push_back((str[i + 1] - str[i] - 26) % 26);
			}
			mp[tmp].push_back(str);
		}

		vector<vector<string>> vv;
		for (auto& kv : mp) {
			vv.push_back(kv.second);
		}
		return vv;
	}
};