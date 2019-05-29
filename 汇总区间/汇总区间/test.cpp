//16msͨ�� 1.ʹ��˫ָ���˼�룬������ʹ��int�ı߽�ֵ��������ķ�Χ�����Խ�����ǿת��long���͵�
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> v;
		int cur = 0, pre = 0;
		while (cur < nums.size())
		{
			pre = cur;
			while (cur + 1 < nums.size() && (long)nums[cur + 1] - (long)nums[cur] == 1)
			{
				cur++;
			}
			if (cur == pre)
				v.push_back(to_string(nums[cur]));
			else
				v.push_back(to_string(nums[pre]) + "->" + to_string(nums[cur]));
			cur++;
		}
		return v;
	}
};