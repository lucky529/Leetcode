//分治问题数组的第一个元素就是这颗子树的根，所以以某个点为索引又可以把这颗树分成新的左子树和右子树
class Solution {
public:
	bool _verifyPreorder(vector<int>& preorder, int start, int end)
	{
		if (start >= end)
		{
			return true;
		}
		int i = start;
		for (; i <= end; i++)
		{
			if (preorder[i] > preorder[start])
				break;
		}
		for (int j = i; j <= end; j++)
		{
			if (preorder[j] < preorder[start])
			{
				return false;
			}
		}
		return _verifyPreorder(preorder, start + 1, i - 1) &&
			_verifyPreorder(preorder, i, end);
	}
	bool verifyPreorder(vector<int>& preorder) {
		return _verifyPreorder(preorder, 0, preorder.size() - 1);
	}
};