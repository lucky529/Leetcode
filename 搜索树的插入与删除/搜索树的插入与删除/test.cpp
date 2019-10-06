//²åÈë²Ù×÷
class Solution {
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root == nullptr) return new TreeNode(val);
		TreeNode* parent = root;
		TreeNode* cur = root;
		while (cur)
		{
			if (cur->val < val)
			{
				parent = cur;
				cur = cur->right;
			}
			else if (cur->val > val)
			{
				parent = cur;
				cur = cur->left;
			}
			else
			{
				return root;
			}
		}
		cur = new TreeNode(val);
		if (cur->val < parent->val)
		{
			parent->left = cur;
		}
		else
		{
			parent->right = cur;
		}
		return root;
	}
};
//É¾³ý²Ù×÷
class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		TreeNode* parent = nullptr;
		TreeNode* cur = root;
		TreeNode* del;
		while (cur) {
			if (cur->val > key) {
				parent = cur;
				cur = cur->left;
			}
			else if (cur->val < key) {
				parent = cur;
				cur = cur->right;
			}
			else {
				if (cur->left == nullptr) {
					if (parent == nullptr) {
						root = cur->right;
					}
					else {
						if (cur == parent->left) {
							parent->left = cur->right;
						}
						else {
							parent->right = cur->right;
						}
					}
					del = cur;
				}
				else if (cur->right == nullptr) {
					if (parent == nullptr) {
						root = cur->left;
					}
					else {
						if (cur == parent->left) {
							parent->left = cur->left;
						}
						else {
							parent->right = cur->left;
						}
					}
					del = cur;
				}
				else
				{
					TreeNode* pre = cur;
					TreeNode* replace = cur->right;
					while (replace->left) {
						pre = replace;
						replace = replace->left;
					}
					cur->val = replace->val;
					if (pre->right == replace) {
						pre->right = replace->right;
					}
					else {
						pre->left = replace->right;
					}
					del = replace;
				}
				break;
			}
		}
		//delete del;
		return root;
	}
};