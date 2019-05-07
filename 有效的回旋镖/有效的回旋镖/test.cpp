// 记住三角形的面积公式 1/2 * ((x1*y2 - x2*y1)+(x2*y3 - x3*y2)+(x3*y1 - x1*y3);
class Solution {
public:
	bool isBoomerang(vector<vector<int>>& points) {
		int x1 = points[0][0], y1 = points[0][1];
		int x2 = points[1][0], y2 = points[1][1];
		int x3 = points[2][0], y3 = points[2][1];
		if ((x1*y2 - x2*y1) + (x2*y3 - x3*y2) + (x3*y1 - x1*y3) == 0) return false;
		else return true;
	}
};