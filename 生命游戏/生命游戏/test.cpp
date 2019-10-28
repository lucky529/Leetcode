//勉强算是广度优先搜索吧，不过这里利用了和矩阵置零相同的思想
//先不要着急立即将他们的状态改变，而是先用其他状态记录一下，然后最后将这些状态统一换成下一次状态

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
		int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				int sum = 0;
				for (int k = 0; k < 8; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[i].size() &&
						(board[nx][ny] == 1 || board[nx][ny] == -2))
						sum++;
				}
				if (board[i][j] == 1 && (sum < 2 || sum > 3))
					board[i][j] = -2;
				if (board[i][j] == 0 && sum == 3)
					board[i][j] = -1;
			}
		}
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == -1)
					board[i][j] = 1;
				else if (board[i][j] == -2)
					board[i][j] = 0;
			}
		}
	}
};