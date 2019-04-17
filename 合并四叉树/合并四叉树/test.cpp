//756ms通过 
class Solution {
public:
	Node* intersect(Node* quadTree1, Node* quadTree2) {
		if (quadTree1->isLeaf && quadTree1->val)//如果是叶子，并且节点为true直接返回
			return quadTree1;
		if (quadTree2->isLeaf && quadTree2->val)
			return quadTree2;
		if (quadTree1->isLeaf && !quadTree1->val)//如果是叶子，并且节点为false，返回相对的节点
			return quadTree2;
		if (quadTree2->isLeaf && !quadTree2->val)
			return quadTree1;

		quadTree1->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
		quadTree1->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
		quadTree1->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
		quadTree1->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

		if (quadTree1->topLeft->isLeaf &&//如果一个区域里的4个部分val相同就转化成一个叶子节点返回
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