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
    //��¿� ����� ť
    queue<int> q;
    //�� �� ���� 0�̴ϱ� 0�� ���� �ִ´�
    q.push(0);
    checked[0] = true;
    int node;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        printf("%d ", x);
        //ť���� �� �� ��带 ���� ���
        for (int i = 0; i < a[x].size(); i++)
        {
            //��µ� ���� ����� ������ �������� �۾�
            node = a[x][i];
            if (!checked[node])
            {
                //��尡 �湮�� �� �ƴ϶�� ť�� ��´�(�湮�� �� �̹� ť�� �ְų�
                //��µƱ� ������ ���� ���� �ʴ´�)
                q.push(node);
                checked[node] = true;
            }
        }
    }
}

int main()
{
    //�Ϻ� ������ ���鳢�� ����� ����ƴٴ� �� ǥ���ϱ� ����
    //���������� ����� ��带 ����
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