//��̬�滮���е��̬��һ����
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len < 2) return 0;
		vector<int> sell(len, 0), buy(len, 0), cool(len, 0);
		buy[0] = -prices[0];
		for (int i = 1; i < len; i++)
		{
			//�����i������ȴ�ڣ�˵��i-1��ʱ����Ʊ�׳�
			cool[i] = sell[i - 1];
			//��i���Ƿ�������Ҳ�����ж�������ô��Ҫ֪����i-1����������ǣ�������ӵ�е�Ǯ���ϵ�ǰ��Ʊ�����
			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
			//��i�쵽�������ж�������ӵ�е�Ǯ���ǲ���໹����ȴ��ǰһ���׳�Ȼ��������
			buy[i] = max(buy[i - 1], cool[i - 1] - prices[i]);
		}
		return max(sell[len - 1], cool[len - 1]);
	}
};