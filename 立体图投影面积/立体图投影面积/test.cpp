//16ms 计算出每个示意图的最高高度相加就行
class Solution {
public:
	int projectionArea(vector<vector<int>>& grid) {
		int row = 0, col = 0;
		for (int i = 0; i < grid.size(); i++) {
			int tmp = grid[i].size();
			row = max(row, tmp);
			col = max(col, i + 1);
		}
		cout << row << " " << col << endl;
		vector<int> x(col, 0);//存放前视图最大数据
		vector<int> y(row, 0);//存放左视图最大数据
		int high = 0, left = 0, cur = 0;
		for (int i = 0; i < grid.size(); i++) {
			int tmp = 0;
			for (int j = 0; j < grid[i].size(); j++) {
				tmp = max(grid[i][j], tmp);
				y[j] = max(grid[i][j], y[j]);
				if (grid[i][j] != 0) high++;
			}
			x[i] = tmp;
		}
		for (auto& e : x) {
			cur += e;
		}
		for (auto& e : y) {
			left += e;
		}
		return high + left + cur;
	}
};