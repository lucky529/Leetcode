//题目可以转化成求符合条件的集合真子集个数。每次从全集中选择若干元素（小球）组成子集（袋子）。集合子集个数为2^n个，使用dfs必然超时。且此题有重复元素，那么就搜索剪枝。
//对于任意两个正整数a, b如果满足 a + b>a*b，则必有一个数为1.可用数论证明：
//设a = 1 + x, b = 1 + y，则1 + x + 1 + y>(1 + x)*(1 + y)，--->  1>x*y，则x，y必有一个为0，即a, b有一个为1.
//推广到任意k个正整数，假设a1, a2, ...ak，如果不满足给定条件，即和sum小于等于积pi，
//如果此时再选择一个数b, 能使其满足sum + b > pi*b，则，b必然为1，且为必要非充分条件。
//反之，如果选择的b>1，则sum + b <= pi*b，即a1, a2, ..., ak, b不满足给定条件。（搜索剪枝的重要依据）
//
//因此，将球按标号升序排序。每次从小到大选择，当选择到a1, a2, ..., ak - 1时满足给定条件，而再增加选择ak时不满足条件（ak必然大于等于max(a1, a2, ..., ak - 1)），继续向后选择更大的数，必然无法满足！因此，可以进行剪枝。
//如果有多个1，即当k = 1时，sum(1)>pi(1)不满足，但下一个元素仍为1，则可以满足1 + 1>1 * 1，所以要判断当前ak是否等于1.
//此外，对于重复数字，要去重复。来源：牛客网
//
#include <stdio.h>
#include <stdlib.h>
int bag[1001], n;

int comp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}
int dfs(int pos, long long sum, long long pi){
	int i, c;
	for (i = pos, c = 0; i<n; ++i){
		sum += bag[i];
		pi *= bag[i];
		if (sum>pi) c += 1 + dfs(i + 1, sum, pi);
		else if (bag[i] == 1) c += dfs(i + 1, sum, pi);
		else break;
		sum -= bag[i];
		pi /= bag[i];
		for (; i<n - 1 && bag[i] == bag[i + 1]; ++i);// duplicate
	}
	return c;
}
int main(){
	int i;
	while (~scanf("%d", &n)){
		for (i = 0; i<n; scanf("%d", &bag[i++]));
		qsort(bag, n, sizeof(int), comp);
		printf("%d\n", dfs(0, 0, 1));
	}
	return 0;
}