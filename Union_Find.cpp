#include <iostream>

using namespace std;

//Ư�� ���� �θ� �˻��Ѵ�(ó���� �ڱ� �ڽ��� �θ�)
//���� ����� �θ� �ڽŰ� �ٸ��ٸ�, ������ ���𰡿� �������ٴ� ��
//�׷��� ������ ����� �θ� �˻��� �� ��尡 ��� ���ϴ��� Ȯ��
int GetParent(int* parent, int x)
{
	if (x != parent[x]) return GetParent(parent, parent[x]);
	return x;
}

//�� ��� �θ� ���ؼ� �θ� ���� ������ ��ħ
void UnionParent(int* parent,int a,int b)
{
	a = GetParent(parent, a);
	b = GetParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

//�� ��� �θ� ���ؼ� ����->����� ���
//�θ� �ٸ���->���� �� �� ���
int FindParent(int* parent, int a, int b)
{
	a = GetParent(parent, a);
	b = GetParent(parent, b);
	if (a == b) return true;
	return false;
}

int main()
{
	int parent[10];
	for (int i = 0; i < 10; i++)
		parent[i] = i;
	//�ƹ� ���ᵵ ������ ���� �������̴ϱ� �θ�� �ڽ�
	UnionParent(parent, 3, 5);
	UnionParent(parent, 0, 5);

	cout << FindParent(parent, 3, 5) << endl;
	cout << GetParent(parent, 0) << endl;
	cout << GetParent(parent, 3) << endl;
	cout << GetParent(parent, 5) << endl;
	return 0;
}