//270ms ����map�洢�±�
class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		int flag = INT_MAX;
		vector<string> v;
		map<string, int> mp;
		for (int i = 0; i < list2.size(); i++)
		{
			mp[list2[i]] = i;
		}
		for (int i = 0; i < list1.size(); i++)
		{
			auto it = mp.find(list1[i]);
			if (it != mp.end())
			{
				if (it->second + i == flag)
				{
					v.push_back(list1[i]);
				}
				if (it->second + i < flag)
				{
					flag = it->second + i;
					v.clear();
					v.push_back(list1[i]);
				}
			}
		}
		return v;
	}
};
//�Ż��汾 ʵ������Ŀ��������������ȫ���� 1.�ж��ҵ����±��Ƿ�С��min 2.С�ھ�clear�������� 3.����ֱ��push
class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		int min_value = INT_MAX;
		vector<string> res;
		for (int i = 0; i<list1.size(); i++){
			for (int j = 0; j<list2.size(); j++){
				if (i + j>min_value){
					break;
				}
				if (list1[i] == list2[j] && i + j<min_value){
					min_value = i + j;
					res.clear();
					res.push_back(list1[i]);
				}
				else if (list1[i] == list2[j] && i + j == min_value){
					res.push_back(list1[i]);
				}
				else{
					continue;
				}
			}
		}
		return res;
	}
};
