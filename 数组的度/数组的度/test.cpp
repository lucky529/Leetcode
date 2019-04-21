//100ms ͨ�� 1.��mapͳ���������Ķ� 2.����Щ��ͬ��Ԫ�ش���������� 3.����һ�����������ʼ���������������������С�ĳ���
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

//48msͨ�� �Ż��㷨 1.��mapͳ����ͬԪ�ص��±�λ�� 2.ͬʱ�������Ķ�
class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, vector<int>> m;
		for (int i = 0; i < nums.size(); i++){
			m[nums[i]].push_back(i);
		}
		int nums_du = 0, min_len = nums.size();
		for (auto iter = m.begin(); iter != m.end(); iter++){
			int size = iter->second.size();//�ж��Ƿ�Ҫ�������Ķ�
			if (size >= nums_du){
				int temp = iter->second[size - 1] - iter->second[0] + 1;
				if (size > nums_du){
					nums_du = size;
					min_len = temp;
				}
				else{
					min_len = min(min_len, temp);//����������ֳ��ִ�����ͬ��鿴�ĸ���С
				}
			}
		}
		return min_len;
	}
};