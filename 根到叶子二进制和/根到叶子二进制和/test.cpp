//20ms通过 一个简单的前序遍历
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int ret = 0;
	void _sumRootToLeaf(TreeNode* root, int num)
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			ret = ret + (((num % 1000000007) << 1) + root->val);
			return;
		}
		num = ((num % 1000000007) << 1) + root->val;
		if (root->left)
			_sumRootToLeaf(root->left, num);
		if (root->right)
			_sumRootToLeaf(root->right, num);
	}
	int sumRootToLeaf(TreeNode* root) {
		int num = 0;
		_sumRootToLeaf(root, num);
		return ret;
	}
};