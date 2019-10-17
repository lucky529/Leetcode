//并查集原理，不相等的等式不可能出现在同一颗数的关系中
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
	bool equationsPossible(vector<string>& equations) {
		UnionSet uset(26);
		for (auto str : equations)
		{
			if (str[1] == '=')
				uset.Union(str[0] - 'a', str[3] - 'a');
		}
		for (auto str : equations)
		{
			if (str[1] == '!')
			{
				if (uset.FindRoot(str[0] - 'a') == uset.FindRoot(str[3] - 'a'))
					return false;
			}
		}
		return true;
	}
};