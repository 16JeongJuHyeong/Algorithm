#include <iostream>
#include <queue>
#include <vector>
#define MAX 10
using namespace std;

int inDegree[MAX]; //�� ����� ��������
vector<int> a[MAX]; //a[x][y] : x�� ����� ��� ��ȣ
queue<int> q; //���� ������ 0�� ���� ����, ������ ǥ���ϱ� ���� ť ���

void TopologySorting()
{
	int result[MAX];
	for (int i = 1; i <= 7; i++)
		if (inDegree[i] == 0) q.push(i);
	for (int i = 1; i <= 7; i++)
	{
		if (q.empty()) return;
		int x = q.front();
		cout << x << " ";
		q.pop();
		for (int j = 0; j < a[x].size(); j++)
		{
			int idx = a[x][j];
			if (--inDegree[idx] == 0) q.push(idx);
		}
	}
}


int main()
{
	a[1].push_back(2); //1�� ��忡�� 2������ ����
	inDegree[2]++; //2�� ��� ��������+1
	a[1].push_back(5); //1�� ��忡�� 5�����ε� ����
	inDegree[5]++; //5�� ��� ��������+1
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;
	TopologySorting();
	return 0;
}