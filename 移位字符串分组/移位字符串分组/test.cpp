//1.�����ֵ��ӳ���ϵ����ĸ֮��ľ��������ΪK���ַ�������Ϊvalue 2.str[i+1]-str[i]-26��ȡģ�Ƿ�ֹ����ѭ��һȦ������
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