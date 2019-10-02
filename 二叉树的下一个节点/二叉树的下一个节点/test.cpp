//分两种情况
//情况一：当前节点的右节点不为空时，那么中序的下一个节点的就是右子树的最左子树
//情况二：当前节点的右节点为空时，那么中序的下一个节点就是一直向上的不为right节点的父节点
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == nullptr) return nullptr;
		TreeLinkNode* pnext = nullptr;
		if (pNode->right != nullptr)
		{
			TreeLinkNode* pleft = pNode->right;
			while (pleft->left)
				pleft = pleft->left;
			pnext = pleft;
		}
		else
		{
			TreeLinkNode* parent = pNode->next;
			while (parent && parent->right == pNode)
			{
				pNode = parent;
				parent = pNode->next;
			}
			pnext = parent;
		}
		return pnext;
	}
};