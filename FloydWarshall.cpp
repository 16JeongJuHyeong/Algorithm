#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 10000000;

int a[4][4] =
{
	{0,5,INF,8},
	{7,0,9,INF},
	{2,INF,0,4},
	{INF,INF,3,0}
};

void FloydWarshall()
{
	for(int k=0;k<4;k++)
		for(int i=0;i<4;i++)
			for (int j = 0; j < 4; j++)
				if (a[i][j] > a[i][k] + a[k][j]) //i->j �Ÿ��� k�� ��ġ�� �ͺ��� ũ�� �ּ� ������� ������Ʈ
					a[i][j] = a[i][k] + a[k][j];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}


int main()
{
	FloydWarshall();

	return 0;
}