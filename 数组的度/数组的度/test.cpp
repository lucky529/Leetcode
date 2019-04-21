//100ms 通过 1.用map统计数组最大的度 2.将这些相同度元素存放在数组中 3.序列一定从这个数开始，到这个数结束，跟新最小的长度
class Solution {
public:
	int FindLength(int num, vector<int>& nums, int max) {
		int pre = 0, cur = 0;
		while (pre < nums.size()) {
			if (nums[pre] == num) {
				break;
			}
			pre++;
		}
		int count = 0, length = 0;
		cur = pre;
		while (cur < nums.size()) {
			if (count == max) {
				break;
			}
			if (nums[pre] == nums[cur]) {
				count++;
			}
			cur++; length++;
		}
		return length;
	}
	int findShortestSubArray(vector<int>& nums) {
		map<int, int> mp;
		for (auto& e : nums) {
			mp[e]++;
		}
		auto it = mp.begin();
		int max = it->second;
		vector<int> v;
		v.push_back(it->first);
		while (it != mp.end()) {
			if (it->second == max)
				v.push_back(it->first);
			if (it->second > max) {
				max = it->second;
				v.clear();
				v.push_back(it->first);
			}
			it++;
		}
		int min = INT_MAX;
		for (int i = 0; i < v.size(); i++) {
			int ret = FindLength(v[i], nums, max);
			min = ret > min ? min : ret;
		}
		return min;
	}
};

//48ms通过 优化算法 1.用map统计相同元素的下标位置 2.同时更新最大的度
class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, vector<int>> m;
		for (int i = 0; i < nums.size(); i++){
			m[nums[i]].push_back(i);
		}
		int nums_du = 0, min_len = nums.size();
		for (auto iter = m.begin(); iter != m.end(); iter++){
			int size = iter->second.size();//判断是否要更新最大的度
			if (size >= nums_du){
				int temp = iter->second[size - 1] - iter->second[0] + 1;
				if (size > nums_du){
					nums_du = size;
					min_len = temp;
				}
				else{
					min_len = min(min_len, temp);//如果俩个数字出现次数相同则查看哪个更小
				}
			}
		}
		return min_len;
	}
};