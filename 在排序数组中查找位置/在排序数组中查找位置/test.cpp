//随便粘贴了一份代码，这种解法是脑子蹦出来的第一种思路，但是如果数组值全部相同且target存在那么扩散的查找复杂度就为on
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty() || target<nums[l] || target>nums[r])
			return vector<int>{-1, -1};
		int l = 0, r = nums.size() - 1;
		int mid;
		while (l <= r){//二分法找到target
			mid = (l + r) / 2;
			if (target == nums[mid])
				break;
			if (target<nums[mid])
				r = mid - 1;
			if (target>nums[mid])
				l = mid + 1;
		}
		if (l>r)
			return vector<int>{-1, -1};
		int i = mid, j = mid;
		while (i >= 0 && j <= r){//向两边扩展
			if (i - 1 >= 0 && nums[i - 1] == target)
				i = i - 1;
			else if (j + 1 <= r&&nums[j + 1] == target)
				j = j + 1;
			else
				break;
		}
		return vector<int>{i, j};
	}
};

//解法2：与上面思路很像，只不过扩散时也使用了二分的思想，比如需要找到target的左边界那么start不动让end = mid-1逐渐缩小
//		 范围

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> v = { -1, -1 };
		if (nums.size() == 0) return v;
		int start = 0, end = nums.size() - 1;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (nums[mid] > target) end = mid - 1;
			else if (nums[mid] < target) start = mid + 1;
			else if (nums[mid] == target) {
				if (mid == 0 || nums[mid - 1] < target) {
					v[0] = mid; break;
				}
				end = mid - 1;
			}
		}
		start = 0, end = nums.size() - 1;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (nums[mid] > target) end = mid - 1;
			else if (nums[mid] < target) start = mid + 1;
			else if (nums[mid] == target) {
				if (mid == nums.size() - 1 || nums[mid + 1] > target) {
					v[1] = mid; break;
				}
				start = mid + 1;
			}
		}
		return v;
	}
};