// 100ms通过  1.找到每个房子前后的供暖器并取最小半径 2.比较每一次最小半径的最大值 3.注意lower_bound的使用
class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(heaters.begin(), heaters.end());
		int ans = 0;
		//思路：
		//对于每座房子，有前后两个供暖器(只有一个供暖器的情况另外判断)，寻找它们之间的较小距离，并与当前最大半径比较更新即可
		for (int i = 0; i<houses.size(); i++)
		{
			int cur = INT_MAX;
			// lower_bound 返回第一个大于等于这个元素的迭代器
			//此时larger就是这座房子右边的供暖器
			//使用*larger来取值,或者heaters[larger-heaters.begin()]
			auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);
			if (larger != heaters.end())
			{
				//如果存在的话 那么就计算它们之间的距离
				cur = *larger - houses[i];
			}
			//如果这个元素没有小于最开始的元素 那么意味着它左边也有一个供暖器
			if (larger != heaters.begin())
			{
				//左边供暖器的位置就是当前larger位置-1
				auto smaller = larger - 1;
				//使用*smaller来取得这个值,更新它们之间的较小值
				cur = min(cur, houses[i] - *smaller);
			}
			ans = max(cur, ans);
		}
		return ans;
	}
};
