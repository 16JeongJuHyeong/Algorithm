#include <iostream>
#include <stdio.h>

using namespace std;

void Heapify(int* heap, int last)
{
    //�� ������ �߰� ����(�ڿ� ����)�� ������ �� ũ�⿡ ���� ������� ���� �ִٴ� �� ������.
    //���� ó���� ��� ��带 ���� �θ� ���� �ڽ��� ��带 ���� �ʿ䰡 ����
    int root, child, temp;
    for (int i = 1; i <= last; i++)
    {
        child = i;
        do
        {
            root = (child - 1) / 2;
            if (heap[root] < heap[child])
            {
                temp = heap[root];
                heap[root] = heap[child];
                heap[child] = temp;
            }
            child = root;
        } while (child != 0);
    }
}


int main()
{
    int N,root,child,temp;
    cin >> N;
    int* heap = new int[N];
    for (int i = 0; i < N; i++)
        cin >> heap[i];
    if (N < 1 || N > 1000000)
        return 0;
    //�� ���� ���� �� ����
    Heapify(heap, N-1);
    
    //�� ���� �߰�����
    for (int i = N-1; i >=0 ; i--)
    {
        //�� �� ���� ������ ����� ��ġ�� �ٲ�->���� ������ ���� ���ĵ� ����
        //��Ʈ �ε����� 0���� �д� -> ���ο� ��Ʈ���� �� ������ ������ �����ϴ��� Ȯ���ϱ� ���� �۾�
        temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        root = 0;
        do
        {
            //���� �ڽ� ��� �ε���. ������ �Ʒ��� ���� �ε����� ����
            child = 2 * root + 1;
            if ( (child < i - 1) && (heap[child] < heap[child + 1])) child++; //���� ������ �ڽ� ��带 ��
            //�� �ڽ� ���� ������ ���� �Ϸ�ƴ� ��� �ε������� �����ؼ� �ȵ�.
            if ( (child < i) && ( heap[root] < heap[child]) )
            {
                //������ ����, ������ �ڽ� ��� �� ū ���� ã���� �θ� ���� ��. �θ� ��尡 ������ �ٲٰ�, �ƴ� �� �ٲ�.
                //���� ���� ������ ��� �� �� ������ ���ĵƴ� ��� �ε����� ������ �ȵ�
                temp = heap[root];
                heap[root] = heap[child];
                heap[child] = temp;
            }
            root = child;
            //���� ��ȯ�� ��(�ȵ�) ����� �ڽĳ�嵵 ���ʷ� ���س�����.
        } while (child < i);
        //������ ���� ������ ���ĵƴ� ��� �ε����� ���� �� ����.
    }
    for (int i = 0; i < N; i++)
        printf("%d ", heap[i]);


    return 0;
}
//����� heapify�� ������·� �ϸ� �ð� ���⵵�� �ö󰡹Ƿ� �߰� �������� ��� ��尡 �ƴ�, Ư�� ��常 ������ �� ������ �����Ѵ�