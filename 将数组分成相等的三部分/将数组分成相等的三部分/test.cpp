//72ms通过 1.首先判断数组和的sum/3为多少 2.进行相加是否能加到sum/3 3.如果末尾还有数字判断是否可以和为0
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

		nowsum = 0;//如果还有数字判断加起来是否为0
		while (cur < A.size()) {
			nowsum += A[cur++];
		}
		if (nowsum == 0 && flag == 3)
			return true;
		else
			return false;
	}
};