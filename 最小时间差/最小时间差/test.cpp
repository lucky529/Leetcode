//32ms 1.ʹ��atoi��ȡÿ��ʱ���Сʱ�ͷ��Ӳ���ת��Ϊ���ӵĺ� 2.����map������ԱȺ�һ����ȥǰһ����min����Сֵ 3.����
//������С��ʱ��ע�����������
class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		int min = INT_MAX;
		map<int, int> mp;
		for (auto e : timePoints)
		{
			int num = 60 * atoi(e.c_str());
			int index = 0;
			while (e[index++] != ':');
			e = e.substr(index);
			mp[num += atoi(e.c_str())]++;
		}
		int left = mp.begin()->first;
		int right = (--mp.end())->first;
		if (left == right) return 0;
		auto cur = ++mp.begin();
		auto pre = mp.begin();
		while (cur != mp.end())
		{
			if (cur->second > 1 || pre->second > 1)
			{
				return 0;
			}
			min = cur->first - pre->first < min ? cur->first - pre->first : min;
			pre = cur; cur++;
		}
		min = (left - 0) + (1440 - right) < min ? (left - 0) + (1440 - right) : min;
		return min;
	}
};