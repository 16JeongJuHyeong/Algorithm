#include <iostream>
using namespace std;

int arr[5] = { 7,4,9,2,5};

void quicksorting(int* data, int start, int end)
{
    int temp;
    if (start >= end)   //원소가 1개인 경우 -> 아무것도 안함
    {
        return;
    }
    int pivot = start;
    int left_index = start; // 피벗보다 큰 수를 담을 왼쪽 인덱스
    int right_index = end; // 피벗보다 작은 수를 담을 오른쪽 인덱스
    while (left_index < right_index)
    {
        // 주의할점 : 왼-오른쪽 인덱스가 피벗 값과 '같아도 넘기고' 작거나 큰 값을 찾아야 한다
        // 탐색 중 피벗 값, 왼쪽 인덱스, 오른쪽 인덱스가 모두 같으면 무한루프에 빠짐
        // 그리고 어차피 같은 값을 넘겨 큰값 , 작은 값을 못 찾으면( ex.모든 수가 같은 경우 ) 피벗값을 제외하고
        // 좌-우측 정렬해서 데이터를 하나씩 줄여나가면 된다
        while ((arr[left_index] <= arr[pivot]) && left_index <= end) left_index++; //피벗보다 큰 수를 찾아 탐색
        while (arr[right_index] >= arr[pivot] && right_index > start) right_index--; //피벗보다 작은 수를 찾아 탐색
        if (left_index < right_index) // 탐색해서 인덱스 간 교환할 차례, 근데 왼쪽 인덱스와 오른쪽 인덱스가 교차하면 안 함
        {
            temp = arr[right_index];
            arr[right_index] = arr[left_index];
            arr[left_index] = temp;
        }
    }
    //반복문을 나왔다는 건 왼쪽 인덱스가 더 크다는 뜻이므로 피벗 데이터와 교환
    if (left_index >= right_index)
    {
        temp = arr[pivot];
        arr[pivot] = arr[right_index];
        arr[right_index] = temp;
    }
    //새로운 피벗 값 기준 좌측, 우측 정렬
    quicksorting(arr, start, right_index - 1);
    quicksorting(arr, right_index + 1, end);
}

int main()
{
    //int N;
    //cin >> N;
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //quicksorting(arr, 0, N - 1);
    quicksorting(arr, 0, 4);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    //for (int i = 0; i < N; i++)
    //    cout << arr[i] << " ";
    return 0;
}