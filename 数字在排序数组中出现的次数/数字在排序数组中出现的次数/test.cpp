//һ����Ҫ���������С�߽�
class Solution {
public:
	int GetNumberOfK(vector<int> nums, int target) {
		vector<int> v = { -1, -1 };
		if (nums.size() == 0) return 0;
		int start = 0, end = nums.size() - 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (nums[mid] > target) end = mid - 1;
			else if (nums[mid] < target) start = mid + 1;
			else if (nums[mid] == target) {
				if (mid == 0 || nums[mid - 1] < target) {
					v[0] = mid; break;
				}
				end = mid - 1;//�����û�е�����߽磬�����ұ߽�
			}
		}
		start = 0, end = nums.size() - 1;
		while (start <= end) {
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
		if (v[1] == -1 || v[0] == -1) return 0;
		return v[1] - v[0] + 1;
	}
};