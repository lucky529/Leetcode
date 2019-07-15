//220msͨ�� 1.���������ά���� 2.ÿ����һ��ֵ�ж�����8�������Ƿ���� 3.ʹ��count���м�¼��Ҫ���Լ�
class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		if (M.size() == 0)
			return{};

		vector<vector<int>> res(M.size(), vector<int>(M[0].size(), 0));

		for (int i = 0; i < M.size(); ++i){
			for (int j = 0; j < M[0].size(); ++j){

				int sum = 0, count = 0;
				//���㲻ͬ���� + ����ĺ�
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