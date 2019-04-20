//排序的思想
class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		if (nums.size() == 3) return nums[0] * nums[1] * nums[2];
		sort(nums.begin(), nums.end());
		return nums[0] * nums[1] * nums[nums.size() - 1] > nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]
			? nums[0] * nums[1] * nums[nums.size() - 1] : nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
	}
};
//映射的思想 代码实在不忍直视
class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		int map[2001] = { 0 };
		for (int i = 0; i < nums.size(); i++)
		{
			map[1000 + nums[i]]++;
		}
		int a = INT_MAX, b = INT_MAX, c = INT_MAX, d = INT_MAX, e = INT_MAX, flag1 = 0, flag2 = 0;
		for (int i = 0; i < 2001; i++) {
			if (flag1 == 2) break;
			while (map[i] > 0) {
				if (a == INT_MAX)
				{
					map[i]--; flag1++;
					a = i - 1000; continue;
				}
				if (b == INT_MAX)
				{
					map[i]--; flag1++;
					b = i - 1000; continue;
				}
				if (flag1 == 2) break;
			}
		}
		memset(map, 0, sizeof(int)* 2001);
		for (int i = 0; i < nums.size(); i++)
		{
			map[1000 + nums[i]]++;
		}
		for (int i = 2000; i >= 0; i--) {
			if (flag1 == 3) break;
			while (map[i] > 0) {
				if (c == INT_MAX)
				{
					map[i]--; flag2++;
					c = i - 1000; continue;
				}
				if (d == INT_MAX)
				{
					map[i]--; flag2++;
					d = i - 1000; continue;
				}
				if (e == INT_MAX)
				{
					map[i]--; flag2++;
					e = i - 1000; continue;
				}
				if (flag2 == 3) break;
			}
		}
		return a*b*c > c*d*e ? a*b*c : c*d*e;
	}
};