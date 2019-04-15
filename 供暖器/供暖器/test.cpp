// 100msͨ��  1.�ҵ�ÿ������ǰ��Ĺ�ů����ȡ��С�뾶 2.�Ƚ�ÿһ����С�뾶�����ֵ 3.ע��lower_bound��ʹ��
class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(heaters.begin(), heaters.end());
		int ans = 0;
		//˼·��
		//����ÿ�����ӣ���ǰ��������ů��(ֻ��һ����ů������������ж�)��Ѱ������֮��Ľ�С���룬���뵱ǰ���뾶�Ƚϸ��¼���
		for (int i = 0; i<houses.size(); i++)
		{
			int cur = INT_MAX;
			// lower_bound ���ص�һ�����ڵ������Ԫ�صĵ�����
			//��ʱlarger�������������ұߵĹ�ů��
			//ʹ��*larger��ȡֵ,����heaters[larger-heaters.begin()]
			auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);
			if (larger != heaters.end())
			{
				//������ڵĻ� ��ô�ͼ�������֮��ľ���
				cur = *larger - houses[i];
			}
			//������Ԫ��û��С���ʼ��Ԫ�� ��ô��ζ�������Ҳ��һ����ů��
			if (larger != heaters.begin())
			{
				//��߹�ů����λ�þ��ǵ�ǰlargerλ��-1
				auto smaller = larger - 1;
				//ʹ��*smaller��ȡ�����ֵ,��������֮��Ľ�Сֵ
				cur = min(cur, houses[i] - *smaller);
			}
			ans = max(cur, ans);
		}
		return ans;
	}
};
