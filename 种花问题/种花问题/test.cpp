//24ms 1.判断当前位置是否为0 2.如果为0紧接着判断当前位置前后是否可以种花 
class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		for (int i = 0; i < flowerbed.size(); ++i) {
			// i == 0 与 i == flowerbed.length - 1 用来防止越界
			if (flowerbed[i] != 1
				&& (i == 0 || flowerbed[i - 1] == 0)
				&& (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
				flowerbed[i] = 1;
				n--;
				i++;
			}
		}
		return n <= 0;
	}
};