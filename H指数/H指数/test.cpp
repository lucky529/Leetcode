//��Ŀ�������ѣ�����������ܺ�����Ľ��
//������������� �Ӻ���ǰ�������ж��������ܱ�ѡȡ����ǰ���������ֽ���ǰһ������֮���ܱ����ö��ٴ�
class Solution {
public:
	int hIndex(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int count = 1, i;
		for (i = nums.size() - 1; i >= 0; i--)
		{
			if (nums[i] < count) break;
			count++;
		}
		int flag = 1;
		for (int j = i; j < nums.size(); j++)
		{
			if (nums[j] > count) {
				flag++;
			}
			else {
				break;
			}
		}
		return count - flag;
	}
};