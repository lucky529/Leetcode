class Solution {
public:
	int tribonacci(int n) {
		if (n == 0) return 0;
		else if (n == 1 || n == 2) return 1;
		else if (n == 3) return 2;
		int a = 1, b = 1, c = 2, d = 4;
		for (int i = 4; i <= n; i++)
		{
			d = a + b + c;
			a = b;
			b = c;
			c = d;
		}
		return d;
	}
};