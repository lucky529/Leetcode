#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

#define N 10
#define M 5

vector<int> v = { 1, 3, 5, 2, 0, 8, 3, 8, 6, 4 };
void Knuth_Durstenfeld_Shuffle()
{
	for (int i = v.size() - 1; i >= 0; i--)
	{
		srand((unsigned)time(NULL));
		swap(v[i], v[rand() % (i + 1)]);
	}
}

//每个元素都有k / x的概率被选中，然后等概率的（1 / k）替换掉被选中的元素
void Reservoir_Sampling()
{
	for (int i = M; i < v.size(); i++)
	{
		srand((unsigned)time(NULL));
		int k = rand() % (i + 1);
		if (k < M)
			swap(v[k], v[i]);
	}
}