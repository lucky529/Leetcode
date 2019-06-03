//题目本身并不难，读懂问题就能很清楚的解决
//对数组进行排序 从后往前找至多有多少文章能被选取，向前往后搜索分界点的前一个数字之多能被引用多少次
class Solution {
public:
	int hIndex(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int count = 1, i;
		for (i = nums.size() - 1; i >= 0; i--)
		{
			if (nums[i] < count) break;
			count++;
		}
		int flag = 1;
		for (int j = i; j < nums.size(); j++)
		{
			if (nums[j] > count) {
				flag++;
			}
			else {
				break;
			}
		}
		return count - flag;
	}
};