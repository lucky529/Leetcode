//16ms通过 1.让图像一层一层的分别向内层旋转，并且只需要旋转3次即可
class Solution {
public:
	void rotate(vector<vector<int>>& nums) {
		int start = 0, end = nums.size() - 1;
		while (start < end) {
			for (int i = 0; i < end - start; i++) {
				swap(nums[start][start + i], nums[end - i][start]);
				swap(nums[end - i][start], nums[end][end - i]);
				swap(nums[end][end - i], nums[start + i][end]);
			}
			start++; end--;
		}
	}
};