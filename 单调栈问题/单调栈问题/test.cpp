#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h>
#include<vector>
#include<stack>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long LL;

stack<int> st;
//�˴�һ����Ҫ�����������ӽ�����־�������������������
for (�����������)
{
	if (ջ�� || ջ��Ԫ�ش��ڵ��ڵ�ǰ�Ƚ�Ԫ��)
	{
		��ջ;
	}
	else
	{
		while (ջ��Ϊ�� && ջ��Ԫ��С�ڵ�ǰԪ��)
		{
			ջ��Ԫ�س�ջ;
			���½��;
		}
		��ǰ������ջ;
	}
}

int FieldSum(int n, vector<int>& v)
{
	v.push_back(inf);
	stack<int> st;
	int sum = 0;
	for (int i = 0; i < (int)v.size(); i++)
	{
		if (st.empty() || v[st.top()] > v[i])
		{
			st.push(i);
		}
		else
		{
			while (!st.empty() && v[st.top()] <= v[i])
			{
				int top = st.top();
				st.pop();
				sum += (i - top - 1);
			}
			st.push(i);
		}
	}
	cout << sum << endl;
	return sum;
}


int largestRectangleArea(vector<int>& heights) {
	heights.push_back(-1);
	stack<int> st;
	int ret = 0, top;
	for (int i = 0; i < heights.size(); i++)
	{
		if (st.empty() || heights[st.top()] <= heights[i])
		{
			st.push(i);
		}
		else
		{
			while (!st.empty() && heights[st.top()] > heights[i])
			{
				top = st.top();
				st.pop();
				int tmp = (i - top)*heights[top];
				if (tmp > ret)
					ret = tmp;
			}
			st.push(top);
			heights[top] = heights[i];
		}
	}
	return ret;
}

void GetMaxSequence(vector<int>& v)
{
	stack<int> st;
	vector<int> vs(v.size()+1);
	vs[0] = 0;
	for (int i = 1; i < vs.size(); i++)
	{
			vs[i] = vs[i - 1] + v[i-1];
	}
	v.push_back(-1);
	int top, start, end, ret = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (st.empty() || v[st.top()] <= v[i])
		{
			st.push(i);
		}
		else
		{
			while (!st.empty() && v[st.top()] > v[i])
			{
				top = st.top();
				st.pop();
				int tmp = vs[i] - vs[top];
				tmp = tmp * v[top];
				if (tmp > ret)
				{
					ret = tmp;
					start = top+1;
					end = i;
				}
			}
			st.push(top);
			v[top] = v[i];
		}
	}
	cout << ret << endl;
	cout << start << " "<<end << endl;
}
int main()
{	
	int n = 6;
	vector<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(6);
	v.push_back(4);
	v.push_back(5);
	v.push_back(2);

		
	GetMaxSequence(v);
	system("pause");
	return 0;
}




