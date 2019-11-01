//并查集原理，将具有关系的节点合并为一棵树
class Solution {
public:
	class UnionSet
	{
	public:
		UnionSet(int size)
		{
			uset.resize(size, -1);
		}
		int FindRoot(int x)
		{
			while (uset[x] >= 0)
			{
				x = uset[x];
			}
			return x;
		}
		bool Union(int x1, int x2)
		{
			int root1 = FindRoot(x1);
			int root2 = FindRoot(x2);
			if (root1 == root2)
				return false;

			uset[root1] += uset[root2];
			uset[root2] = root1;
			return true;
		}
		size_t Count()const
		{
			size_t count = 0;
			for (auto e : uset)
			{
				if (e < 0)
					++count;
			}
			return count;
		}
	private:
		vector<int> uset;
	};
	int findCircleNum(vector<vector<int>>& M) {
		UnionSet uset(M.size());
		for (int i = 0; i < M.size(); i++)
		{
			for (int j = 0; j < M[i].size(); j++)
			{
				if (M[i][j] == 1)
					uset.Union(i, j);
			}
		}
		return uset.Count();
	}
};