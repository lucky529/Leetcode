//使用两个大矩形的面积减去重跌部分的面积
class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		long int x1, x2, y1, y2;
		long int area1 = (C - A)*(D - B);
		long int area2 = (G - E)*(H - F);
		x1 = A>E ? A : E;
		y1 = B>F ? B : F;
		x2 = C<G ? C : G;
		y2 = D<H ? D : H;
		long int area = (x2 - x1)*(y2 - y1);

		if ((x2 - x1)>0 && (y2 - y1)>0)
			return area1 + area2 - area;

		return area1 + area2;
	}
};