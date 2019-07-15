//220ms通过 1.遍历这个二维数组 2.每遇到一个值判断他的8个方向是否存在 3.使用count进行记录需要除以几
class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		if (M.size() == 0)
			return{};

		vector<vector<int>> res(M.size(), vector<int>(M[0].size(), 0));

		for (int i = 0; i < M.size(); ++i){
			for (int j = 0; j < M[0].size(); ++j){

				int sum = 0, count = 0;
				//计算不同方向 + 本身的和
				for (int px = -1; px < 2; ++px)
				for (int py = -1; py < 2; ++py)
				if (i + px > -1 && i + px < M.size() && j + py > -1 && j + py < M[0].size())
					sum += M[px + i][py + j], count++;

				res[i][j] = sum / count;

			}
		}
		return res;
	}
};