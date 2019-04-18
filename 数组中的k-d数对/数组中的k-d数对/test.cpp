//���˺ܾ�û��ͨ��������˫ָ����ð������һ����˼��������������ͣ����˴����˼�뷢��map�Ľӿ�Ӧ�úúø�ϰһ���� 
//64msͨ�� 1.��mapͳ�����ֺ����ֳ��ֵĴ��� 2.Ȼ��ֱ�ӵ���count�ӿڲ����Ƿ���ڵ�ǰֵ��K�ĺ�
class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) return 0;
		map<int, int> mp;
		for (auto& e : nums)
		{
			mp[e]++;
		}
		int count = 0;
		auto it = mp.begin();
		while (it != mp.end())
		{
			if (k)
			{
				int num = it->first + k;
				if (mp.count(num)) count++;
			}
			else
			{
				if (it->second > 1)//��ʱֻҪ���Ƿ������ͬ��ֵ
					count++;
			}
			it++;
		}
		return count;
	}
};
