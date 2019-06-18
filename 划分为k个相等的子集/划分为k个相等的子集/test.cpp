//�ݹ���ݵ�˼��
//1.���ǿ��Դ���һ��vector����vector��ÿ��Ԫ�ص���һ��Ͱ�����Ƿ����һ�ֿ���ʹ����Ԫ�ط��뵽Ͱ����������
//2.������Ϊ�ؼ��������ǵ�����Ӧ�ôӴ�С���У���Ϊ����ȡ���Ĵ���Խ����ô�ݹ�Ĵ���Ҳ��Խ��
//3.���ǵĵݹ�ʹ��index���Ʒ���Ͱ��Ԫ�ص��±꣬�����ǰԪ�ط��뵱Ͱ�в�����С��Ŀ�����������ô�ͻ���һ��Ͱ
//4.���������������ô���Ǿ͵ݹ鵽��һ�β鿴��һ��Ԫ���Ƿ���ͬ���������Ͱ��
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
		sort(nums.rbegin(), nums.rend());//����ܹؼ�
		return dfs(path, nums, target, 0);
	}
};
//��˼��ʹ���ڷָ������������������Ч���������Ƶ��ⶼ����ʹ������˼��