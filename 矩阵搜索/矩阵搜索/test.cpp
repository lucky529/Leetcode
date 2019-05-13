//16ms 利用了二分查找的思想，杨氏矩阵
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0) return false;
		int row = 0, col = matrix[0].size() - 1;
		while (row < matrix.size() && col >= 0)
		{
			if (matrix[row][col] < target)
				row++;
			else if (matrix[row][col] > target)
				col--;
			else
				return true;
		}
		return false;
	}
};