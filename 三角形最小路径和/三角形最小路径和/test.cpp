//��һ�棬�Ƚϴ��һ�棬ʹ�ö�̬�滮��˼�룬�����������
class Solution {
public:
	int minimumTotal(vector<vector<int>>& nums) {
		if (nums.size() == 1) return nums[0][0];
		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < nums[i].size(); j++){
				if (j == nums[i].size() - 1) {
					nums[i][j] += nums[i - 1][j - 1];
					continue;
				}
				int up = nums[i - 1][j];
				int upl;
				if (j - 1 >= 0) upl = nums[i - 1][j - 1];
				else upl = INT_MAX;

				nums[i][j] += min(up, upl);
			}
		}

		int ret = INT_MAX;
		for (int i = 0; i < nums[nums.size() - 1].size(); i++)
		{
			if (nums[nums.size() - 1][i] < ret) ret = nums[nums.size() - 1][i];
		}
		return ret;
	}
};
//�ڶ��棬ֱ�Ӵ���������⣬������ȥ�жϱ߽������Ĺ���
int minimumTotal(vector<vector<int>> &triangle)
{
	for (int i = triangle.size() - 2; i >= 0; i--)
	for (int j = 0; j < triangle[i].size(); j++)
		triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
	return triangle[0][0];
}