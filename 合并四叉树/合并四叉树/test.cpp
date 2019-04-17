//756msͨ�� 
class Solution {
public:
	Node* intersect(Node* quadTree1, Node* quadTree2) {
		if (quadTree1->isLeaf && quadTree1->val)//�����Ҷ�ӣ����ҽڵ�Ϊtrueֱ�ӷ���
			return quadTree1;
		if (quadTree2->isLeaf && quadTree2->val)
			return quadTree2;
		if (quadTree1->isLeaf && !quadTree1->val)//�����Ҷ�ӣ����ҽڵ�Ϊfalse��������ԵĽڵ�
			return quadTree2;
		if (quadTree2->isLeaf && !quadTree2->val)
			return quadTree1;

		quadTree1->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
		quadTree1->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
		quadTree1->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
		quadTree1->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

		if (quadTree1->topLeft->isLeaf &&//���һ���������4������val��ͬ��ת����һ��Ҷ�ӽڵ㷵��
			quadTree1->topRight->isLeaf &&
			quadTree1->bottomLeft->isLeaf &&
			quadTree1->bottomRight->isLeaf &&
			quadTree1->topLeft->val == quadTree1->topRight->val &&
			quadTree1->topRight->val == quadTree1->bottomLeft->val &&
			quadTree1->bottomLeft->val == quadTree1->bottomRight->val)
		{
			quadTree1->val = quadTree1->topLeft->val;
			quadTree1->isLeaf = true;
		}
		return quadTree1;
	}
};