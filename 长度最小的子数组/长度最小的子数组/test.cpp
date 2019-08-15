//ǰ��ָ�뷨 1.��ǰ��������������preָ��++��Ѱ����һ���������������� 2.���û�н���whileѭ��˵��һֱû�����������
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int cur = 0, pre = 0, ret = INT_MAX, sum = 0, flag = 0;
		while (cur < nums.size())
		{
			if (cur < nums.size() && sum < s)
			{
				sum += nums[cur++];
			}
			while (sum >= s)
			{
				ret = min(ret, cur - pre);
				flag = 1;
				sum -= nums[pre++];
			}
		}
		return flag == 1 ? ret : 0;
	}
};