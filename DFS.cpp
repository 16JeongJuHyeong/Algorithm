#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

bool checked[7] = { false }; //방문확인용
vector<int> a[7]; //탐색할 데이터들

//1. 가장 최상단 노드를 방문, 출력한다
//2. 인접한 노드들 중 방문하지 않은 노드가 있는지 확인
//3. 있다면 방문 후 출력, 그 노드에서 바로 인접한 노드를 찾아 위 과정 반복

void DFS(int x)
{
    if (checked[x]) return;
    checked[x] = true;
    cout << x << " ";
    for (int i = 0; i < a[x].size(); i++)
        if (!checked[a[x][i]])
            DFS(a[x][i]);
}

int main()
{
    //일부 노드들은 노드들끼리 양방향 연결됐다는 걸 표현하기 위해
    //벡터형으로 연결된 노드를 저장
    a[0].push_back(1);
    a[0].push_back(2);
    a[1].push_back(0);
    //a[1].push_back(2);
    a[1].push_back(3);
    a[1].push_back(4);
    a[2].push_back(0);
    //a[2].push_back(1);
    a[2].push_back(5);
    a[2].push_back(6);
    a[3].push_back(1);
    a[3].push_back(4);
    a[4].push_back(1);
    a[4].push_back(3);
    a[5].push_back(2);
    a[5].push_back(6);
    a[6].push_back(2);
    a[6].push_back(5);
    DFS(0);

    return 0;
}