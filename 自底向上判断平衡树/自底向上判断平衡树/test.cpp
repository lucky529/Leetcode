//16ms通过 每次都给上一层传递高度高的那一边子树的高度
//		   然后判断高度是否左右相差超过一
class Solution {
public:
	bool flag = true;
	int _isBalanced(TreeNode* root)
	{
		if (root == nullptr) return 0;
		int left = _isBalanced(root->left) + 1;
		int right = _isBalanced(root->right) + 1;

		if (abs(left - right) > 1)
			flag = false;
		return max(left, right);
	}
	bool isBalanced(TreeNode* root) {
		_isBalanced(root);
		return flag;
	}
};