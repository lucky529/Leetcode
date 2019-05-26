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
	vector<TreeNode*> CreatTree(int l, int r)
	{
		vector<TreeNode*> ret;
		if (r < l)
		{
			ret.push_back(nullptr); return ret;
		}
		for (int i = l; i <= r; i++)
		{
			vector<TreeNode*> lt = CreatTree(l, i - 1);
			vector<TreeNode*> rt = CreatTree(i + 1, r);
			for (auto ll : lt)
			{
				for (auto rr : rt)
				{
					TreeNode* root = new TreeNode(i);
					root->left = ll;
					root->right = rr;
					ret.push_back(root);
				}
			}
		}
		return ret;
	}
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return vector<TreeNode*>{};
		return CreatTree(1, n);
	}
};