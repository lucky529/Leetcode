//675msͨ�� 1.ʹ��map������ʵ����set���У�ȥ�� 2.������������һ��˵���������õ�һ�룬��ȻС��һ��Ҳ����ζ��ֻ����
//map.size()��
class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		int part = candies.size() / 2;
		map<int, int> mp;
		for (auto& e : candies)
		{
			mp[e]++;
		}
		if (mp.size() >= part)
			return part;
		else
			return mp.size();
	}
};
//���в��� ���ǿ죬���Ǹо���ʵ��
class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		int n[200001] = { 0 };
		int count = 0;
		for (auto tmp : candies){
			if (n[tmp + 100000] == 0){
				n[tmp + 100000] = 1;
				count++;
			}
		}
		int size = candies.size() / 2;
		return min(count, size);
	}
};