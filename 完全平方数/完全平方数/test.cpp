//��򵥵ķ�ʽ����dfs����ÿ�αȽϼ����Ƿ�Ϊ��Сֵ
class Solution {
public:
	int ret = INT_MAX;
	void dfs(vector<int>& v, int index, int sum, int target, int count)
	{
		if (sum == target)
		{
			ret = min(count, ret);
			return;
		}
		if (sum > target)
			return;
		for (int i = index; i >= 0; i--)
		{
			if (sum < target)
				dfs(v, i, sum + v[i], target, count + 1);
		}
	}
	int numSquares(int n) {
		vector<int> v;
		for (int i = 1;; i++)
		{
			if (i*i > n) break;
			v.push_back(i*i);
		}
		dfs(v, v.size() - 1, 0, n, 0);
		return ret;
	}
};

//�������dp˼��
class Solution {
public:	
	int numSquares(int n) {
		vector<int> dp(n + 1);
		dp[0] = 0;//��ʾ�ߵ���һ��ֻ��Ҫ0��
		for (int i = 1; i <= n; i++)
		{
			dp[i] = i;//���ұ�ʾÿһ������Ҫi�����ܵ���
			for (int j = 1; i - j*j >= 0; j++)
			{
				dp[i] = min(dp[i], dp[i - j*j] + 1);
			}
		}
		return dp[n];
	}
};

//4��ƽ��������ƽ������ �κ�һ�������������Ա�ʾ�ɲ������ĸ�������ƽ��֮�͡� 
//���ۣ���������ƽ���Ͷ������n���ĸ���������������ض����� n=4^a(8b+7)

//���м�ֱ̫����
int numSquares(int n) {
	//�ȸ��������ᵽ�Ĺ�ʽ����Сn
	while (n % 4 == 0) {
		n /= 4;
	}
	//������㹫ʽ �򷵻�4
	if (n % 8 == 7) {
		return 4;
	}
	//���ж���С������Ƿ������һ������ƽ������������ƽ���ĺ����
	int a = 0;
	while ((a * a) <= n) {
		int b = sqrt((n - a * a));
		if (a * a + b * b == n) {
			//������� �����ﷵ��
			if (a != 0 && b != 0) {
				return 2;
			}
			else{
				return 1;
			}
		}
		a++;
	}
	//������� ����3
	return 3;
}