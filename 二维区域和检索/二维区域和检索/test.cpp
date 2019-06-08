class NumMatrix {
private:// 矩阵面积相减
	vector<vector<int>> vint;
public:
	//构造一个左上角和矩阵，[i][j]处的值是左上角所有元素的和
	NumMatrix(vector<vector<int>>& matrix) {
		vint = matrix;
		if (vint.empty())    return;
		int r = matrix.size(), c = matrix[0].size();
		for (int i = 1; i<r; i++)
			vint[i][0] += vint[i - 1][0];
		for (int j = 1; j<c; j++)
			vint[0][j] += vint[0][j - 1];
		for (int i = 1; i<r; i++)
		for (int j = 1; j<c; j++){
			vint[i][j] = vint[i - 1][j] + vint[i][j - 1] + matrix[i][j] - vint[i - 1][j - 1];
		}
	}
	int sumRegion(int row1, int col1, int row2, int col2) {
		if (vint.empty())    return 0;
		if (row1 == 0 && col1 == 0)
			return vint[row2][col2];
		if (row1 == 0)
			return vint[row2][col2] - vint[row2][col1 - 1];
		if (col1 == 0)
			return vint[row2][col2] - vint[row1 - 1][col2];
		return vint[row2][col2] + vint[row1 - 1][col1 - 1] - vint[row1 - 1][col2] - vint[row2][col1 - 1];
	}
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix* obj = new NumMatrix(matrix);
* int param_1 = obj->sumRegion(row1,col1,row2,col2);
*/