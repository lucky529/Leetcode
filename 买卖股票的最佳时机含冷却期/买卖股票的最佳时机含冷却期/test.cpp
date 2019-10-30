//动态规划，有点变态的一道题
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len < 2) return 0;
		vector<int> sell(len, 0), buy(len, 0), cool(len, 0);
		buy[0] = -prices[0];
		for (int i = 1; i < len; i++)
		{
			//如果第i天是冷却期，说明i-1天时将股票抛出
			cool[i] = sell[i - 1];
			//第i天是否卖出，也就是判断利润，那么需要知道是i-1天卖利润大还是，将现在拥有的钱加上当前股票利润大
			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
			//第i天到底买不买，判断现在所拥有的钱，是不买多还是冷却期前一天抛出然后今天买多
			buy[i] = max(buy[i - 1], cool[i - 1] - prices[i]);
		}
		return max(sell[len - 1], cool[len - 1]);
	}
};