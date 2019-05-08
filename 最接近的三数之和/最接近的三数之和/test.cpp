//20ms通过 1.与三数之和的思想完全相同，我们利用一个min变量来记录当前三数与target最小的差距
//		   2.如果当前三数之和就是为target那么我们直接返回target即可
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), min = INT_MAX, sum = 0;
		for (int i = 0; i < n; i++) {
			int start = i + 1, end = n - 1;
			while (start < end) {
				int tmp = nums[start] + nums[end] + nums[i];
				if (abs(tmp - target) < min) {
					min = abs(tmp - target); sum = tmp;
				}
				if (tmp > target)
					end--;
				else if (tmp < target)
					start++;
				else
					return target;
			}
		}
		return sum;
	}
};