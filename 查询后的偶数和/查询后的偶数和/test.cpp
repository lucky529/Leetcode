// 224ms 1.如果查询前这个数字位偶数，就先减去这个数 2.查询后这个数是偶数，就加入sum，否则break
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