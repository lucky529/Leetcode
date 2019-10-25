//最初版16ms通过 1.找到旋转数组的中间（寻找的过程是二分查找） 2.将这个数组划分为两段区间 3.判断target在哪个区间中
//在所在区间中进行二分查找

class Solution {
public:
	int barsearch(vector<int>& nums, int s, int e, int target) {
		int start = s;
		int end = e;
		while (start < end) {
			int mid = (start + end) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			else if (nums[mid] > target) {
				end = mid;
			}
			else {
				start = mid + 1;
			}
		}
		if (nums[start] == target) return start;
		return -1;
	}
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		if (nums.size() == 1 && nums[0] != target) return -1;
		else if (nums.size() == 1 && nums[0] == target) return 0;
		int start = 0, end = nums.size() - 1, mid = 0;
		while (nums[start] >= nums[end]) {
			if (end - start == 1) {
				mid = start; break;
			}
			mid = start + ((end - start) >> 1);
			if (nums[mid] > nums[start])
				start = mid;
			else if (nums[mid] < nums[end])
				end = mid;
		}
		if (target >= nums[0] && target <= nums[mid])
			return barsearch(nums, 0, mid, target);
		else if (target >= nums[mid + 1] && target <= nums[nums.size() - 1])
			return barsearch(nums, mid + 1, nums.size() - 1, target);
		else
			return -1;
	}
};
//优化版本 1.思路同上
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		int start = 0, end = nums.size() - 1;
		while (start < end)//不用<=为了防止数组中只有一个数字而出现的死循环
		{
			int mid = start + ((end - start) >> 1);
			if (nums[mid] > nums[end]) start = mid + 1;
			else end = mid;
		}
		int split = start;
		start = 0, end = nums.size() - 1;
		if (nums[split] <= target && target <= nums[nums.size() - 1])
			start = split;
		else
			end = split;
		while (start <= end)//这是使用左[右]类型的搜索方式
		{
			int mid = start + ((end - start) >> 1);
			if (nums[mid] == target) return mid;
			else if (nums[mid] > target) end = mid - 1;
			else start = mid + 1;
		}
		return -1;
	}
};