#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

bool checked[7] = { false };
vector<int> a[7];

void BFS()
{
    //출력에 사용할 큐
    queue<int> q;
    //맨 위 노드는 0이니까 0을 먼저 넣는다
    q.push(0);
    checked[0] = true;
    int node;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        printf("%d ", x);
        //큐에서 맨 앞 노드를 꺼내 출력
        for (int i = 0; i < a[x].size(); i++)
        {
            //출력된 노드와 연결된 노드들을 가져오는 작업
            node = a[x][i];
            if (!checked[node])
            {
                //노드가 방문된 게 아니라면 큐에 담는다(방문된 건 이미 큐에 있거나
                //출력됐기 때문에 가져 오지 않는다)
                q.push(node);
                checked[node] = true;
            }
        }
    }
}

int main()
{
    //일부 노드들은 노드들끼리 양방향 연결됐다는 걸 표현하기 위해
    //벡터형으로 연결된 노드를 저장
    a[0].push_back(1);
    a[0].push_back(2);
    a[1].push_back(0);
    a[1].push_back(2);
    a[1].push_back(3);
    a[1].push_back(4);
    a[2].push_back(0);
    a[2].push_back(1);
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
    BFS();

    return 0;
}