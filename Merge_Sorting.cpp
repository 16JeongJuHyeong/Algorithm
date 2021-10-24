#include <iostream>
using namespace std;

int sorted[8]; // 정렬 배열은 반드시 전역 변수
//다른 함수들에서 각자 배열 복사본을 생성하는 비효율적 행동을 막기 위함

void merge(int* arr, int m, int middle, int n)
{// 두 배열을 합쳐나가는 과정
    int left_arr_idx = m; //두 배열 중 왼쪽 배열
    int right_arr_idx = middle + 1; // 두 배열 중 오른쪽 배열
    //배열을 나눴다 해서 독립된 공간에 있는 것처럼 보이지만
    //실제론 배열은 연속된 메모리 공간에 할당되므로 사실 오른쪽 배열은 왼쪽 배열 바로 다음이다
    int final_arr_idx = m;


    //기본적인 과정은 두 배열(이해를 돕기 위해 충분히 긴 배열들이 있다고 가정)이 있다면
    //둘 다 가장 왼쪽값은 가장 작은 값들이다 ( 이전에 정렬이 됐다고 가정)
    //두 값을 비교해 가장 작은 값을 합칠 배열의 첫번째 칸 부터 넣고,
    //옮겨진 값보다 큰 값과 다른 작은 값을 비교한다. 위 작업을 반복해
    //정렬된 값이 새 배열로 들어간다
    while (left_arr_idx <= middle && right_arr_idx <= n)
    {
        if (arr[left_arr_idx] >= arr[right_arr_idx])
        {
            sorted[final_arr_idx] = arr[right_arr_idx];
            right_arr_idx++;
        }
        else
        {
            sorted[final_arr_idx] = arr[left_arr_idx];
            left_arr_idx++;
        }
        final_arr_idx++;
    }
    //위에서 두 배열의 값을 하나씩 빼 새 배열에 넣었다.
    //경우에 따라 한쪽 배열의 값이 먼저 다 빠진다면, 나머지 배열의 값이 남기 때문에
    //남은 값들을 새 배열에 모두 넣어준다
    if (left_arr_idx > middle)
    {
        for (int i = right_arr_idx; i <= n; i++)
        {
            sorted[final_arr_idx] = arr[i];
            final_arr_idx++;
        }
    }
    else
    {
        for (int i = left_arr_idx; i <= middle; i++)
        {
            sorted[final_arr_idx] = arr[i];
            final_arr_idx++;
        }

    }
    for (int i = m; i <= n; i++)
        arr[i] = sorted[i];
}

void mergeSort(int* arr, int m, int n) 
{ //배열을 먼저 쪼개기 위한 작업
    if (m < n)
    {
        //m이 n보다 크거나 같다는 건 첫번째 배열 인덱스가 마지막 인덱스와 같거나 크다는 건데
        //그럼 배열이 하나라는 뜻이므로 나눌 게 없다
        int middle = (m + n) / 2; //공평하게 중간씩 나눈다
        mergeSort(arr, m, middle); //재귀함수로 부르면 나뉜 배열이 다시 반으로 나눈다
        mergeSort(arr, middle + 1, n);
        merge(arr, m, middle, n);
        //먼저 호출된 이 함수에서 merge를 하기 때문에 원래 배열의 merge는 나중에 실행되어
        //최종적으로 정렬을 거친다
    }
}

int main()
{
    int arr[8] = { 20,8,10,4,7,6,5,4 };
    mergeSort(arr, 0, 7);
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    return 0;
}