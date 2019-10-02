//���������
//���һ����ǰ�ڵ���ҽڵ㲻Ϊ��ʱ����ô�������һ���ڵ�ľ�������������������
//���������ǰ�ڵ���ҽڵ�Ϊ��ʱ����ô�������һ���ڵ����һֱ���ϵĲ�Ϊright�ڵ�ĸ��ڵ�
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