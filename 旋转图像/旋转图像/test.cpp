//16msͨ�� 1.��ͼ��һ��һ��ķֱ����ڲ���ת������ֻ��Ҫ��ת3�μ���
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