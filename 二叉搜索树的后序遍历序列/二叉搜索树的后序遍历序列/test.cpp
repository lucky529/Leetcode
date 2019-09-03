//将数组每次都切分为左子树，右子树，根
//当找到分界点后，再次比根小的树就一定不是二叉搜索树
class Solution {
public:
	bool func(vector<int> nums, int begin, int end)
	{
		if (begin >= end) return true;
		int i = begin;
		for (; i < end - 1; i++)
		{
			if (nums[i] > nums[end])
				break;
		}
		int j = i;
		for (; j < end - 1; j++)
		{
			if (nums[j] < nums[end])
				return false;
		}
		return func(nums, begin, i - 1) && func(nums, i, end - 1);
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0) return false;
		return func(sequence, 0, sequence.size() - 1);
	}
};