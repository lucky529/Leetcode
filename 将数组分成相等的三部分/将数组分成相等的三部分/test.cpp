//72msͨ�� 1.�����ж�����͵�sum/3Ϊ���� 2.��������Ƿ��ܼӵ�sum/3 3.���ĩβ���������ж��Ƿ���Ժ�Ϊ0
class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& A) {
		int sum = 0, cur = 0, flag = 0, nowsum = 0;
		for (auto& e : A) {
			sum += e;
		}
		sum /= 3;
		while (cur < A.size()) {
			while (cur < A.size() && nowsum != sum){
				nowsum += A[cur++];
				while (cur < A.size() && A[cur] == 0)
					cur++;
			}
			flag++; nowsum = 0;
			if (flag == 3) break;
		}

		nowsum = 0;//������������жϼ������Ƿ�Ϊ0
		while (cur < A.size()) {
			nowsum += A[cur++];
		}
		if (nowsum == 0 && flag == 3)
			return true;
		else
			return false;
	}
};