//��һ��������k�ְ취
//�ڶ���������k*k�ְ취
//���������ˣ���������ɫ�������������3��ͬ����3��ͬ 
//1.���3��2��ͬ����ô3������1��ͬ�����Կ���Ⱦ����ɫ��Ϊ��k*k��*(k - 1) 
//2.���3��2��ͬ���ڲ���3��ͬ��ǰ���£�Ⱦɫ����Ϊk*��k - 1��
class Solution {
public:
	int numWays(int n, int k) {
		if (n == 0 || k == 0) return 0;
		if (n == 1) return k;

		vector<int> dp(n + 1, 0);
		dp[1] = k;
		dp[2] = k*k;
		for (int i = 3; i <= n; i++)
		{
			dp[i] = (dp[i - 2] + dp[i - 1])*(k - 1);
		}
		return dp.back();
	}
};