//16ms通过 1.从右往左找到数组中第一个nums[i-1] < nums[i]的位置 
//		   2.然后从i之后找到第一个大于nums[i-1]且最接近他的数字
//		   3.交换nums[i - 1], 和最接近他的数字，之后将i之后的数字前后两个两个进行交换
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		for (int i = nums.size() - 1; i >= 1; i--) {
			if (nums[i - 1] < nums[i]) {
				int cur = nums.size() - 1;
				while (cur >= i) {
					if (nums[cur] > nums[i - 1]) {
						break;
					}
					cur--;
				}
				swap(nums[i - 1], nums[cur]);

				int end = nums.size() - 1;
				while (i < end) {
					swap(nums[i], nums[end]);
					i++; end--;
				}
				return;
			}
		}
		reverse(nums.begin(), nums.end());
	}
};