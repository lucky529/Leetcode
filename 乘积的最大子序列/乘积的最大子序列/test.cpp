//如果数组的数是负数，那么会导致最大的变最小的，最小的变最大的。因此交换两个的值
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int Max = INT_MIN, imax = 1, imin = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 0) swap(imax, imin);
			imax = max(nums[i], imax*nums[i]);
			imin = min(nums[i], imin*nums[i]);

			Max = max(Max, imax);
		}
		return Max;
	}
};
//思路： 求最大值，可以看成求被0拆分的各个子数组的最大值。
//
//当一个数组中没有0存在，则分为两种情况：
//
//1.负数为偶数个，则整个数组的各个值相乘为最大值；
//
//2.负数为奇数个，则从左边开始，乘到最后一个负数停止有一个“最大值”，从右边也有一个“最大值”，比较，得出最大值。
class Solution {
	public int maxProduct(int[] nums) {
		int a = 1;
		int max = nums[0];

		for (int num : nums){
			a = a*num;
			if (max<a)max = a;
			if (num == 0)a = 1;

		}
		a = 1;
		for (int i = nums.length - 1; i >= 0; i--){
			a = a*nums[i];
			if (max<a)max = a;
			if (nums[i] == 0)a = 1;
		}
		return max;
	}
}