//220ms通过 1.使用曼哈顿距离作为map的key，而用一个一维数组作为value排序即可
class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		multimap<int, vector<int>> mp;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				mp.insert(make_pair(abs(i - r0) + abs(j - c0), vector<int>{i, j}));
			}
		}

		vector<vector<int>> vv;
		for (const auto& e : mp) {
			vv.push_back(e.second);
		}
		return vv;
	}
};