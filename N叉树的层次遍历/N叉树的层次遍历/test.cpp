/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/
class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		if (root == nullptr) return{ {} };
		queue<Node*> q;
		vector<vector<int>> vv;
		int index = 0;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			vv.push_back(vector<int>());
			for (int i = 0; i < size; i++)
			{
				auto cur = q.front(); q.pop();
				for (int j = 0; j < cur->children.size(); j++)
				{
					q.push(cur->children[j]);
				}
				vv[index].push_back(cur->val);
			}
			index++;
		}
		return vv;
	}
};