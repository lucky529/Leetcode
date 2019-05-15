//12ms 贼恶心的下标控制
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& nums) {
		if (nums.size() == 0) return{};
		vector<int> v;
		int cur = 0, row = nums[0].size(), col = nums.size(), count = (min(row, col) + 1) / 2;
		while (cur < count)
		{
			for (int i = cur; i < row - cur; i++)
				v.push_back(nums[cur][i]);
			for (int i = cur + 1; i < col - cur; i++)
				v.push_back(nums[i][row - cur - 1]);
			for (int i = row - cur - 2; i >= cur && col - cur - 1 != cur; i--)
				v.push_back(nums[col - cur - 1][i]);
			for (int i = col - cur - 2; i >= cur + 1 && row - cur - 1 != cur; i--)
				v.push_back(nums[i][cur]);
			cur++;
		}
		return v;
	}
};
