//�ܼ򵥣�������������Ϊ���������е�ǰ׺������ÿ��num�ʹ���0ʱ��ô�����¿�ʼ��������
int main()
{
	vector<int> v = { 2, 2, 3, 3, 1 };
	int num = v[0], Min = INT_MAX;
	for (int i = 1; i < v.size(); i++)
	{
		if (num > 0)
			num = v[i];
		else
			num += v[i];
		Min = min(Min, num);
	}
	cout << Min << endl;
	system("pause");
	return 0;
}