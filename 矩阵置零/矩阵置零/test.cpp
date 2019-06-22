//120msͨ�� ʵ���Ͼ���ͳ����һ�к�����Ҫ���㣬ʹ��setȥ��(���Բ�ʹ��set����������Ŵ�����ȫ��ͬ)
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		unordered_set<int> row;
		unordered_set<int> col;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					row.insert(i);
					col.insert(j);
				}
			}
		}
		for (auto& e : row)
		{
			for (int j = 0; j < matrix[0].size(); j++)
				matrix[e][j] = 0;
		}
		for (auto& e : col)
		{
			for (int j = 0; j < matrix.size(); j++)
				matrix[j][e] = 0;
		}
	}
};