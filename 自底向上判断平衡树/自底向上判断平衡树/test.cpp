//16msͨ�� ÿ�ζ�����һ�㴫�ݸ߶ȸߵ���һ�������ĸ߶�
//		   Ȼ���жϸ߶��Ƿ���������һ
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