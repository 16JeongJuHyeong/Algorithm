#include <iostream>

using namespace std;

//특정 값의 부모를 검사한다(처음엔 자기 자신이 부모)
//만약 노드의 부모가 자신과 다르다면, 이전에 무언가에 합쳐졌다는 뜻
//그래서 합쳐진 노드의 부모를 검사해 그 노드가 어디에 속하는지 확인
int GetParent(int* parent, int x)
{
	if (x != parent[x]) return GetParent(parent, parent[x]);
	return x;
}

//두 노드 부모 비교해서 부모 작은 쪽으로 합침
void UnionParent(int* parent,int a,int b)
{
	a = GetParent(parent, a);
	b = GetParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

//두 노드 부모 비교해서 같다->연결된 노드
//부모 다르다->연결 안 된 노드
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
	//아무 연결도 안했을 때는 독립적이니까 부모는 자신
	UnionParent(parent, 3, 5);
	UnionParent(parent, 0, 5);

	cout << FindParent(parent, 3, 5) << endl;
	cout << GetParent(parent, 0) << endl;
	cout << GetParent(parent, 3) << endl;
	cout << GetParent(parent, 5) << endl;
	return 0;
}