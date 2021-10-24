#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

bool checked[7] = { false }; //�湮Ȯ�ο�
vector<int> a[7]; //Ž���� �����͵�

//1. ���� �ֻ�� ��带 �湮, ����Ѵ�
//2. ������ ���� �� �湮���� ���� ��尡 �ִ��� Ȯ��
//3. �ִٸ� �湮 �� ���, �� ��忡�� �ٷ� ������ ��带 ã�� �� ���� �ݺ�

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
    //�Ϻ� ������ ���鳢�� ����� ����ƴٴ� �� ǥ���ϱ� ����
    //���������� ����� ��带 ����
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