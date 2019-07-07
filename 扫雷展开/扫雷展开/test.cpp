//63ms通过 广度优先搜索
class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
		int dy[8] = { 0, -1, 1, -1, 1, 0, -1, 1 };
		int n = board.size(), m = board[0].size();
		vector<vector<bool>> vis(n, vector<bool>(m, false));
		int x = click[0], y = click[1];
		if (board[x][y] == 'M') { board[x][y] = 'X'; return board; }
		queue<pair<int, int>> q; q.push(pair<int, int>(x, y)); vis[x][y] = true;
		while (!q.empty()){
			pair<int, int> p = q.front(); q.pop();
			int sum = 0;
			for (int i = 0; i<8; ++i){
				int xx = p.first + dx[i], yy = p.second + dy[i];
				if (xx >= 0 && xx<n&&yy >= 0 && yy<m&&board[xx][yy] == 'M') ++sum;
				//!!!yy<m wocnmd
			}
			if (sum == 0){
				board[p.first][p.second] = 'B';
				for (int i = 0; i<8; ++i){
					int xx = p.first + dx[i], yy = p.second + dy[i];
					if (xx >= 0 && xx<n&&yy >= 0 && yy<m&&!vis[xx][yy] && board[xx][yy] == 'E'){
						q.push(pair<int, int>(xx, yy)); vis[xx][yy] = true;
					}
				}
			}
			else board[p.first][p.second] = sum + '0';
		}
		return board;
	}
};