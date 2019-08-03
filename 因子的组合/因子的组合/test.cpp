//使用组合总和的思想 
//这里总结一下递归中下标的控制
递归中使用：
//	i :			表示当前数字可以重复使用，并且之后的数字都比当前数字小，组合总和1（可使用重复数字）
//	i + 1 :		表示当前数字不可以重复使用，并且后面的数字都比当前数字小 组合总和2（不可以使用重复数字） 组合
//				总和3 组合0 子集
//	index + 1 : 全排列中使用，表示当前下标的数字和下一个数字交换
class Solution {
public:
	vector<vector<int>> vv;
	vector<int> v;
	void _getFactors(int n, int index)
	{
		if (n == 1)
		{
			if (v.size() > 1)//一个数最少分成俩个因子
			{
				vv.push_back(v);
			}
		}
		for (int i = index; i <= n; i++)
		{
			if (n % i == 0)
			{
				v.push_back(i);
				_getFactors(n / i, i);
				v.pop_back();
			}
		}
	}
	vector<vector<int>> getFactors(int n) {
		if (n == 1) return{};
		_getFactors(n, 2);
		return vv;
	}
};