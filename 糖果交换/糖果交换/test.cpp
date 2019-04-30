//�����㷨 ��ȥ�Լ���ǰӵ�е���ţ����ϱ��˵�ǰ����Ų鿴�Ƿ���������
class Solution {
public:
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		int sumA = 0, sumB = 0, sum;
		for (auto& e : A)
			sumA += e;
		for (auto& e : B)
			sumB += e;

		sum = (sumA + sumB) / 2;
		for (int i = 0; i < B.size(); i++)
		{
			for (int j = 0; j < A.size(); j++)
			{
				if (sumA + B[i] - A[j] == sum)
				{
					return{ A[j], B[i] };
				}
			}
		}
		throw ("error num");
	}
};

//�Ż��㷨
class Solution {
public:
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		int sa = 0, sb = 0;
		for (int x : A) sa += x;
		for (int x : B) sb += x;
		int num = (sb - sa) / 2;
		set<int> setB;
		for (auto& e : B) setB.insert(e);

		for (auto& e : A)
		if (setB.find(e + num) != setB.end())
			return{ e, e + num };
		throw nullptr;
	}
};