#include <iostream>
using namespace std;
int main()
{
    int temp,i,j;
    int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
    for (i = 1; i < 9; i++)
    {
        for(j = i ; (j>=0)&& arr[j] > arr[j+1] ;  j--) // 앞의 데이터와 비교하다가 자신보다 값이 작으면 바꾸는 걸 멈춘다 ( 오름차순 ) -> 효율
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            //개념적으론 자신보단 큰 수, 자신보다 작은 수 사이에 들어가지만 배열이므로 자신보다 큰 수들을 한 칸씩 뒤로 옮겨야 하므로
            //swap으로 큰 수들은 뒤로 옮긴다
        }
    }
    for (i = 0; i < 10; i++)
        cout << arr[i] << " ";

    return 0;
}