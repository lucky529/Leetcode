#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int main(){
	//�������и��������ӣ�����ַ���ֻ����Сд��ĸ����Ȼ�𰸾Ͳ�Ӧ����56��
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2){
		//ֻ����Сд��ĸ���ַ������Կ���26���Ƶ�����
		//��s1��s2������len2����
		s1.append(len2 - s1.size(), 'a');
		s2.append(len2 - s2.size(), (char)('z' + 1));
		vector<int> array;
		for (int i = 0; i<len2; i++){
			array.push_back(s2[i] - s1[i]);
		}
		int result = 0;
		for (int i = len1; i <= len2; i++){
			for (int k = 0; k<i; k++){
				result += array[k] * pow(26, i - 1 - k);
			}
		}
		//�����ַ�����󶼲�������s2�����������Ҫ��1��
		cout << result - 1 << endl;
	}
	return 0;
}