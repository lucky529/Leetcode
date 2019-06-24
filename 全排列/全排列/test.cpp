//20ms通过 思路是让每一个字符都和之后的字符进行交换位置，但是记得在将位置交换完之后将位置换回来
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

//全排列||，数据可能重复，多一个去重的步骤就可以了
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