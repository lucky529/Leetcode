/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//ʹ��˫ָ��������
//�����ǰ��preָ����ڽڵ�p����ôcurһ��ָ����p�ĺ��
class Solution {
public:
	TreeNode* ret = nullptr;
	void Inorder(TreeNode* p, TreeNode*& cur, TreeNode*& pre)
	{
		if (cur == nullptr) return;

		Inorder(p, cur->left, pre);
		if (pre == p)
			ret = cur;
		pre = cur;
		Inorder(p, cur->right, pre);
	}
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (root == nullptr) return nullptr;
		TreeNode* cur = root, *pre = nullptr;
		Inorder(p, cur, pre);
		return ret;
	}
};