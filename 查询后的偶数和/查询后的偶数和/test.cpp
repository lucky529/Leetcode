// 224ms 1.�����ѯǰ�������λż�������ȼ�ȥ����� 2.��ѯ���������ż�����ͼ���sum������break
class Solution {
public:
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
		int sum = 0;
		vector<int> v;
		for (auto& e : A)
		{
			if (e % 2 == 0) sum += e;
		}
		for (auto& e : queries)
		{
			if (A[e[1]] % 2 == 0)
			{
				sum -= A[e[1]];
				A[e[1]] += e[0];
				if (A[e[1]] % 2 == 0)
				{
					sum += A[e[1]];
					v.push_back(sum);
				}
				else
				{
					v.push_back(sum);
				}
			}
			else
			{
				A[e[1]] += e[0];
				if (A[e[1]] % 2 == 0)
				{
					sum += A[e[1]];
					v.push_back(sum);
				}
				else
				{
					v.push_back(sum);
				}
			}
		}
		return v;
	}
};