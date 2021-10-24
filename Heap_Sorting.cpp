#include <iostream>
#include <stdio.h>

using namespace std;

void Heapify(int* heap, int last)
{
    //힙 정렬의 중간 과정(뒤에 있음)은 노드들이 값 크기에 따라 순서대로 놓여 있다는 걸 가정함.
    //따라서 처음에 모든 노드를 돌며 부모 노드와 자신의 노드를 비교할 필요가 있음
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
    //힙 정렬 시작 전 정리
    Heapify(heap, N-1);
    
    //힙 정렬 중간과정
    for (int i = N-1; i >=0 ; i--)
    {
        //맨 위 노드와 마지막 노드의 위치를 바꿈->이제 마지막 노드는 정렬된 상태
        //루트 인덱스를 0으로 둔다 -> 새로운 루트값이 힙 정렬의 조건을 만족하는지 확인하기 위한 작업
        temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        root = 0;
        do
        {
            //왼쪽 자식 노드 인덱스. 좌측은 아래와 같은 인덱스를 가짐
            child = 2 * root + 1;
            if ( (child < i - 1) && (heap[child] < heap[child + 1])) child++; //왼쪽 오른쪽 자식 노드를 비교
            //단 자식 노드는 이전에 정렬 완료됐던 노드 인덱스까지 도달해선 안됨.
            if ( (child < i) && ( heap[root] < heap[child]) )
            {
                //위에서 왼쪽, 오른쪽 자식 노드 중 큰 값을 찾으면 부모 노드와 비교. 부모 노드가 작으면 바꾸고, 아님 안 바꿈.
                //또한 왼쪽 오른쪽 노드 둘 다 이전에 정렬됐던 노드 인덱스를 넘으면 안됨
                temp = heap[root];
                heap[root] = heap[child];
                heap[child] = temp;
            }
            root = child;
            //이제 교환이 된(안된) 노드의 자식노드도 차례로 비교해나간다.
        } while (child < i);
        //하지만 역시 이전에 정렬됐던 노드 인덱스를 넘을 순 없다.
    }
    for (int i = 0; i < N; i++)
        printf("%d ", heap[i]);


    return 0;
}
//참고로 heapify를 재귀형태로 하면 시간 복잡도가 올라가므로 중간 과정에서 모든 노드가 아닌, 특정 노드만 가지고 힙 정렬을 유지한다