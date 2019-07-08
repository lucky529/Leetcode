/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//使用两个栈来存储树的节点 奇数层先push左树再push右树 偶数层则相反
class Solution {
public:
	void levelOrder(TreeNode* root) {
		if (root == nullptr) return{ {} };
		stack<TreeNode*> st[2];
		int cur = 0, next = 1;
		st[cur].push(root);
		while (!st[0].empty() || !st[1].empty())
		{
			int size = st[cur].size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = st[cur].top(); st[cur].pop();
				if (cur == 0)
				{
					if (node->left)
						st[next].push(node->left);
					if (node->right)
						st[next].push(node->right);
				}
				else
				{
					if (node->right)
						st[next].push(node->right);
					if (node->left)
						st[next].push(node->left);
				}
				cout << node->val << " ";
			}
			cur = 1 - cur;
			next = 1 - next;
		}
	}
};