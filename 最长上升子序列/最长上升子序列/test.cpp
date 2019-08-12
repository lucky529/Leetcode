//nums = [10 9 2 5 3 4 101 18], tail = []
//i = 0，tail = [10] ，size = 1
//i = 1，tail = [9]，size = 1，因为9比10小，且没有比9更小的数，所以直接把10替换为9
//i = 2，tail = [2]，size = 1，同上
//i = 3，tail = [2, 5]， size = 2， tail的最后一个数字小于5，所以可以直接把5放到后面
//i = 4，tail = [2, 3]， size = 2， 2 < 3 < 5，所以3相对于5是更优解
//i = 5，tail = [2, 3, 4]，size = 3，4 > 3, 直接append
//i = 6，tail = [2, 3, 4, 101]， size = 4， 101 > 4, 直接append
//i = 7， tail = [2, 3, 4, 18], size = 4，4 < 18 < 101。 所以结果为 4
//优化： 使用二分法找到 当前数需要插入到tail中的位置

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int maxL = 0;
		vector<int> dp(nums.size(), 0);
		for (int num : nums) {
			// 二分法查找, 也可以调用库函数如binary_search
			int lo = 0, hi = maxL;
			while (lo < hi) {
				int mid = lo + (hi - lo) / 2;
				if (dp[mid] < num)
					lo = mid + 1;
				else
					hi = mid;
			}
			dp[lo] = num;
			if (lo == maxL)
				maxL++;
		}
		return maxL;
	}
};

class Solution {//lower_bound的底层是使用二分查找实现的
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> arr;
		for (auto num : nums) {
			if (arr.empty() || num > arr.back()) {
				arr.push_back(num);
			}
			else {
				*(lower_bound(arr.begin(), arr.end(), num)) = num;
			}
		}
		return arr.size();
	}
};

//动态规划的思想，但是实际上时间复杂度还是on2
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		vector<int> dp(nums.size(), 1);
		for (int i = 1; i < nums.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		int ret = dp[0];
		for (auto& e : dp)
		{
			if (e > ret)
				ret = e;
		}
		return ret;
	}
};