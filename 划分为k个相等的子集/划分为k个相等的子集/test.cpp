//递归回溯的思想
//1.我们可以创建一个vector，把vector的每个元素当成一个桶，看是否存在一种可能使所有元素放入到桶中满足条件
//2.这里尤为关键的是我们的数组应该从大到小排列，因为放入取出的次数越少那么递归的次数也就越少
//3.我们的递归使用index控制放入桶中元素的下标，如果当前元素放入当桶中不满足小于目标的条件，那么就换下一个桶
//4.如果满足条件，那么我们就递归到下一次查看下一个元素是否能同样放入这个桶种
class Solution {
public:
	bool dfs(vector<int>& path, vector<int>& nums, int target, int index)
	{
		if (index >= nums.size())
		{
			for (auto& e : path){
				if (e != target)
					return false;
			}
			return true;
		}
		for (int i = 0; i < path.size(); i++)
		{
			if (path[i] + nums[index] > target) continue;
			path[i] += nums[index];
			if (dfs(path, nums, target, index + 1))return true;
			path[i] -= nums[index];
		}
		return false;
	}
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum%k != 0) return false;
		int target = sum / k;
		vector<int> path(k, 0);
		sort(nums.rbegin(), nums.rend());//这里很关键
		return dfs(path, nums, target, 0);
	}
};
//此思想使用于分割俩个部分子数组更高效，所有类似的题都可以使用这种思想