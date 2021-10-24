#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct node* treepointer; //��� �����͸� treepointer�� ����ϰڴ�

typedef struct node // ��� �� ����: ������, ����/������ �ڽ�
{
	int data;
	treepointer leftchild, rightchild;
}node;

void preorder(treepointer ptr)
{
	if (ptr)
	{
		cout << ptr->data << " " ;
		preorder(ptr->leftchild);
		preorder(ptr->rightchild);
	}
}

int main()
{
	node nodes[15];
	for (int i = 0; i < 15; i++)
	{
		nodes[i].data = i;
		nodes[i].leftchild = NULL;
		nodes[i].rightchild = NULL;
	}
	for (int i = 1; i < 15; i++)
	{
		if (i % 2 == 1)
			nodes[(i-1) / 2].leftchild = &nodes[i];
		else
			nodes[(i - 1) / 2].rightchild = &nodes[i];
	}
	preorder(&nodes[0]);
	return 0;
}