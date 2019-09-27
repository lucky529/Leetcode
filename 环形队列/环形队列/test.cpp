#include<iostream>
#include<pthread.h>
#include<semaphore.h>
#include<vector>
#include<stdlib.h>
using namespace std;

class Ring
{
private:
	vector<int> q;
	int cap;
	sem_t data;
	sem_t space;
	int dd;
	int ss;
public:
	Ring(int capacity)
		:cap(capacity)
	{
		sem_init(&data, 0, 0);
		sem_init(&space, 0, cap);
		dd = 0;
		ss = 0;
	}
	void PushData(int& value)
	{
		sem_wait(&space);
		q[dd++] = value;
		dd %= cap;
		sem_post(&data);
	}
	void Pop(int& value)
	{
		sem_wait(&data);
		value = q[ss++];
		ss %= cap;
		sem_post(&space);
	}
	~Ring()
	{
		sem_destory(&data);
		sem_destory(&space);
	}
};