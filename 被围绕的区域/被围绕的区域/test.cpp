//˼·�ܼ� �����������еġ�O��������Ϊ��*�����Ƚ�������Χ�ġ�*�����й��������������Ϊ��O��
//������һ�����齫��*������Ϊ��X��
class Solution {
public:
	void Set(vector<vector<char>>& grid, int x, int y) {
		grid[x][y] = 'O';
		if (x - 1 >= 0 && grid[x - 1][y] == '*') Set(grid, x - 1, y);
		if (x + 1<grid.size() && grid[x + 1][y] == '*') Set(grid, x + 1, y);
		if (y - 1 >= 0 && grid[x][y - 1] == '*') Set(grid, x, y - 1);
		if (y + 1<grid[0].size() && grid[x][y + 1] == '*') Set(grid, x, y + 1);
	}
	void solve(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == 'O')
					board[i][j] = '*';
			}
		}
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == '*' && (i == 0 || i == board.size() - 1 || j == 0 ||
					j == board[i].size() - 1))
					Set(board, i, j);
			}
		}
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == '*')
					board[i][j] = 'X';
			}
		}
	}
};