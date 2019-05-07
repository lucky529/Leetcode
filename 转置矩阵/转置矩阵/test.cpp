//每行的同一列作为新的一行
class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		vector<vector<int>> vv(A[0].size());
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < A[i].size(); j++)
			{
				vv[j].push_back(A[i][j]);
			}
		}
		return vv;
	}
};