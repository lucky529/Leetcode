//44ms 1.判断当前数字是否有比他大的数字 2.判断当前数字是否有比他小的数字 3.如果计数为零说明序列有序，不为零取小的count
//判断是否为1
class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int n = nums.size(), a = nums[0], b = nums[n - 1], count1 = 0, count2 = 0;
		for (int i = 0; i<n; i++){
			b = min(b, nums[n - 1 - i]);
			a = max(a, nums[i]);
			if (a != nums[i])
				count2++;
			if (b != nums[n - 1 - i])
				count1++;
		}
		if (count1 == 0 && count2 == 0)
			return true;
		return min(count1, count2) == 1;
	}
};