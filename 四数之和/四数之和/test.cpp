// 60msͨ�� 1.˼·������֮����ͬ���̶��������֣�ʣ����������ʹ��˫ָ��Ѱ��
//			2.����ʹ��set���԰�������ȥ��
//			3.���ص�ʱ��ֱ�ӽ�set�ĵ�����������ά����ͺ�
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		set<vector<int>> s;
		for (int i = 0; i < n; i++)
		{
			if (i > 0 && nums[i - 1] == nums[i]) continue;
			for (int j = i + 1; j < n; j++)
			{
				int start = j + 1, end = n - 1;
				while (start < end)
				{
					int tmp = nums[start] + nums[end] + nums[i] + nums[j];
					if (tmp == target && i < j)
					{
						s.insert(vector<int>{nums[start], nums[end], nums[i], nums[j]});
						while (start < end && nums[start] == nums[start + 1]) start++;
						while (start < end && nums[end] == nums[end - 1]) end--;
						start++; end--;
					}
					else if (tmp > target) end--;
					else start++;
				}
			}
		}
		return vector<vector<int>>(s.begin(), s.end());
	}
};