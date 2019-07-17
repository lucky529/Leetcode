//158/162ͨ�� 
class Solution {
public:
	string largestTimeFromDigits(vector<int>& A) {
		int a = -1, b = -1, c = -1, d = -1;
		for (int i = 0; i < 4; i++)
		{
			if (A[i] > a && A[i] <= 2)
			{
				a = A[i];
			}
		}
		if (a == -1) return "";
		auto it = find(A.begin(), A.end(), a);
		A.erase(it);
		for (int i = 0; i < A.size(); i++)
		{
			if (a != 0 && A[i] > b && A[i] <= 3)
			{
				b = A[i];
			}
			else if (a <= 1 && A[i] > b && A[i] <= 9)
			{
				b = A[i];
			}
		}
		if (b == -1) return "";
		it = find(A.begin(), A.end(), b);
		A.erase(it);
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] > c && A[i] <= 5)
			{
				c = A[i];
			}
		}
		if (c == -1) return "";
		it = find(A.begin(), A.end(), c);
		A.erase(it);
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] > d && A[i] <= 9)
			{
				d = A[i];
			}
		}
		if (d == -1) return "";
		it = find(A.begin(), A.end(), d);
		A.erase(it);
		return to_string(a) + to_string(b) + ':' + to_string(c) + to_string(d);
	}
};

//��������ѭ��ѡ���������һ��Сʱλѡ���˺��ʵ��������Ƿ���λ�����ϣ���ôСʱλ��Ҫ���¾���ѡ�����������û�к��ʵĽ��
class Solution {
public:
	string largestTimeFromDigits(vector<int>& A) {
		sort(A.begin(), A.end());
		for (int i = 3; i >= 0; i--){
			if (A[i]>2) continue;
			for (int j = 3; j >= 0; j--) {
				if (j == i || A[i] == 2 && A[j]>3) continue;
				for (int k = 3; k >= 0; k--) {
					if (k == i || k == j || A[k]>5) continue;
					return "" + to_string(A[i]) + to_string(A[j]) + ':' + to_string(A[k]) + to_string(A[6 - i - j - k]);
				}
			}
		}
		return "";
	}
};