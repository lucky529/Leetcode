// ����֮�ͱ����ⷨ��
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> vv;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				for (int k = 0; k < nums.size(); k++)
				{
					if (i != j && j != k && i != k && nums[i] + nums[j] + nums[k] == 0)
					{
						vector<int> v = { nums[i], nums[j], nums[k] };
						sort(v.begin(), v.end());
						if (find(vv.begin(), vv.end(), v) == vv.end())
							vv.push_back(v);
					}
				}
			}
		}
		return vv;
	}
};
//˫ָ�룺1.��ԭ����������� 2.ÿ�ι̶�һ������ 3.����ʹ���0������ָ�������������ָ������
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<vector<int>> vv;
		for (int i = 0; i < n; i++)
		{
			if (i > 0 && nums[i - 1] == nums[i]) continue;
			int start = i + 1, end = n - 1;
			while (start < end)
			{
				int tmp = nums[start] + nums[end] + nums[i];
				if (tmp == 0)
				{
					vv.push_back(vector<int>{nums[start], nums[end], nums[i]});
					while (start < end && nums[start] == nums[start + 1]) start++;
					while (start < end && nums[end] == nums[end - 1]) end--;
					start++; end--;
				}
				else if (tmp > 0) end--;
				else start++;
			}
		}
		return vv;
	}
};