//������֮�͵�˼·��ͬ 1.�����ǰ�����Ѿ�����������˵��right�߽�ĵ������left�߽������ͬ��������ɽ��
					// �����ǰ�Ľ�����ڻ��ߵ��ڽ������ôend--
class Solution {
public:
	int threeSumSmaller(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), count = 0;
		for (int i = 0; i < n; i++)
		{
			int start = i + 1, end = n - 1;
			while (start < end)
			{
				int tmp = nums[i] + nums[start] + nums[end];
				if (tmp < target)
				{
					count += (end - start);
					start++;
				}
				if (tmp >= target)
					end--;
			}
		}
		return count;
	}
};