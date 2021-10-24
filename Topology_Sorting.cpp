#include <iostream>
#include <queue>
#include <vector>
#define MAX 10
using namespace std;

int inDegree[MAX]; //각 노드의 진입차수
vector<int> a[MAX]; //a[x][y] : x에 연결된 노드 번호
queue<int> q; //진입 차수가 0인 노드들 저장, 순서를 표현하기 위해 큐 사용

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
	a[1].push_back(2); //1번 노드에서 2번으로 연결
	inDegree[2]++; //2번 노드 진입차수+1
	a[1].push_back(5); //1번 노드에서 5번으로도 연결
	inDegree[5]++; //5번 노드 진입차수+1
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