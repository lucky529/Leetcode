//16msͨ�� 1.̰���㷨�������ǰ����Ϊ1��ֱ���������� 2.���Ϊ0����һ�� 3.����ߵ���cur == bits.size() - 1˵��ֻ��
//��һ�ֱ��뷽ʽ
class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		int cur = 0;
		while (cur < bits.size())
		{
			if (cur == bits.size() - 1)
				return true;
			if (bits[cur] == 0)
			{
				cur++;
			}
			else if (bits[cur] == 1)
			{
				cur += 2;
			}
		}
		return false;
	}
};