//0ms通过 1.三指针，遇到0丢到数组的最前面 ，遇到2丢到数组的最后面 ，遇到1直接跳过
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int i = 0, l = 0, r = nums.size() - 1;
		while (i <= r){
			if (i<l || nums[i] == 1)
				i++;
			else if (nums[i] == 0)
				swap(nums[i], nums[l++]);
			else if (nums[i] == 2)
				swap(nums[i], nums[r--]);
		}
	}
};