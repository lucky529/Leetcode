//24ms 1.�жϵ�ǰλ���Ƿ�Ϊ0 2.���Ϊ0�������жϵ�ǰλ��ǰ���Ƿ�����ֻ� 
class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		for (int i = 0; i < flowerbed.size(); ++i) {
			// i == 0 �� i == flowerbed.length - 1 ������ֹԽ��
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