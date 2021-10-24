#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int>> a[7];
int d[7];

void diks(int start)
{
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start)); //���� ó���� �ڱ��ڽ������� ���(�̰� �翬�� 0)�� ���۳��
	while (!pq.empty())
	{
		int distance = -pq.top().first;
		//�ִ����� ū ���� ������ �̵�. �츰 �ּ����� �ʿ�� �ϹǷ� pq�� push �� �� ����� �� ������ �־��ش�
		//�׷� ������ ū ������ �������� �۱� ������ �� �ڷ� ����. �� ÷�� 0�̴ϱ� �������
		//distance�� start���� �ش� �������� �Ÿ��� ���� ����
		int current = pq.top().second;
		// �湮�� ��� (÷�� start ���)
		pq.pop();
		if (d[current] < distance) continue;
		// �̹� ������ ���� ���� ���� ������ �۴ٸ� ������ �ʿ� ����
		// *pq�� ��ΰ� �� ū ����(ex 1->3�� 7�ε� 1->2->3�� 5�� ���, 1->2->3 �� ť�� ���� ���� �־
		// �̰� ���߿� d �迭�� ���� �ٲ�. 1->3 �� ���߿� ������ �� �̹� ���ŵ� ���¶� ����
		for (int i = 0; i < a[current].size(); i++)
		{//���� �湮���� ���� ����� ���� �� �˻�
			int next = a[current][i].second; 
			//������ ���
			int nextDistance = distance + a[current][i].first;
			//���������� �湮�� ������ �Ÿ� + �湮�� ��忡�� ���������� �Ÿ�
			if (nextDistance < d[next])
			{//���������� �湮�� ������ �Ÿ� + �湮�� ��忡�� ���������� �Ÿ� < start���� �ش� ���� �ֱٱ��� ���ŵ� �Ÿ�
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
}

int main()
{
	for (int i = 0; i <= number; i++)
		d[i] = INF;
	//a[from].push_back(make_pair(���, to ���))
	a[1].push_back(make_pair(2, 2)); //1���� 2�� ���� ��� 2
	a[1].push_back(make_pair(5, 3)); //1���� 3���� ���� ��� 5
	a[1].push_back(make_pair(1, 4)); //1���� 4�� ���� ��� 1

	a[2].push_back(make_pair(2, 1));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(2, 4));

	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(3, 2));
	a[3].push_back(make_pair(3, 4));
	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(5, 6));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(1, 5));

	a[5].push_back(make_pair(1, 3));
	a[5].push_back(make_pair(1, 4));
	a[5].push_back(make_pair(2, 6));

	a[6].push_back(make_pair(5, 3));
	a[6].push_back(make_pair(2, 5));

	diks(1);
	return 0;
}