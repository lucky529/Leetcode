//20msͨ�� ˼·����ÿһ���ַ�����֮����ַ����н���λ�ã����Ǽǵ��ڽ�λ�ý�����֮��λ�û�����
class Solution {
public:
	vector<vector<int>> vv;
	void _permute(int index, vector<int>& nums)
	{
		if (index == nums.size())
			vv.push_back(nums);

		for (int i = index; i < nums.size(); i++)
		{
			swap(nums[index], nums[i]);
			_permute(index + 1, nums);
			swap(nums[index], nums[i]);
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() <= 0) return vv;
		_permute(0, nums);
		return vv;
	}
};

//ȫ����||�����ݿ����ظ�����һ��ȥ�صĲ���Ϳ�����
class Solution {
public:
	set<vector<int>> s;
	void _permute(int index, vector<int> nums)
	{
		if (index == nums.size())
			s.insert(nums);

		for (int i = index; i < nums.size(); i++)
		{
			if (i != index && nums[i] == nums[index])
			{
				continue;
			}
			swap(nums[index], nums[i]);
			_permute(index + 1, nums);
			//swap(nums[index],nums[i]);                
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.size() <= 0) return{ {} };
		sort(nums.begin(), nums.end());
		_permute(0, nums);
		return vector<vector<int>>(s.begin(), s.end());
	}
};