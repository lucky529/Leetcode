//����һ������Ա����Ϣ�����ݽṹ����������Ա��Ψһ��id����Ҫ�� �� ֱϵ������id��
//
//���磬Ա��1��Ա��2���쵼��Ա��2��Ա��3���쵼��������Ӧ����Ҫ��Ϊ15, 10, 5����ôԱ��1�����ݽṹ��[1, 15, [2]]��Ա��2�����ݽṹ��[2, 10, [3]]��Ա��3�����ݽṹ��[3, 5, []]��ע����ȻԱ��3Ҳ��Ա��1��һ���������������ڲ�����ֱϵ���������û��������Ա��1�����ݽṹ�С�
//
//��������һ����˾������Ա����Ϣ���Լ�����Ա��id���������Ա������������������Ҫ��֮�͡�
//
//ʾ�� 1:
//
//���� : [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
//��� : 11
// ���� :
//Ա��1�������Ҫ����5����������ֱϵ����2��3������2��3����Ҫ�Ⱦ�Ϊ3�����Ա��1������Ҫ���� 5 + 3 + 3 = 11
/*
// Employee info
class Employee {
public:
// It's the unique ID of each node.
// unique id of this employee
int id;
// the importance value of this employee
int importance;
// the id of direct subordinates
vector<int> subordinates;
};
*/
// �������������100msͨ��
class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		int sum = 0;
		for (int i = 0; i < employees.size(); i++)
		{
			if (employees[i]->id == id)
			{
				if (employees[i]->subordinates.size() == 0)
					return employees[i]->importance;
				for (int j = 0; j < employees[i]->subordinates.size(); j++)
				{
					sum = sum + getImportance(employees, employees[i]->subordinates[j]);
				}
				sum += employees[i]->importance;
			}
		}
		return sum;
	}
};