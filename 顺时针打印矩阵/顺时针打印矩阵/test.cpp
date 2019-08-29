//!!!!!!!!!!!!!!!!!!!!!!!!!! +1/2
//控制边界时要减一
class Solution {
public:
	vector<int> printMatrix(vector<vector<int>> matrix) {
		if (matrix.size() == 0) return{};
		int cur = 0, row = matrix.size(), col = matrix[0].size();
		int flag = (min(row, col) + 1) / 2;
		vector<int> v;
		while (cur < flag)
		{
			for (int i = cur; i < col - cur; i++)
				v.push_back(matrix[cur][i]);
			for (int i = cur + 1; i < row - cur; i++)
				v.push_back(matrix[i][col - cur - 1]);
			for (int i = col - cur - 2; i >= cur && row - cur - 1 != cur; i--)
				v.push_back(matrix[row - cur - 1][i]);
			for (int i = row - cur - 2; i >= cur + 1 && col - cur - 1 != cur; i--)
				v.push_back(matrix[i][cur]);
			cur++;
		}
		return v;
	}
};