#include <iostream>
using namespace std;
int main()
{
    int temp,i,j;
    int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
    for (i = 1; i < 9; i++)
    {
        for(j = i ; (j>=0)&& arr[j] > arr[j+1] ;  j--) // ���� �����Ϳ� ���ϴٰ� �ڽź��� ���� ������ �ٲٴ� �� ����� ( �������� ) -> ȿ��
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            //���������� �ڽź��� ū ��, �ڽź��� ���� �� ���̿� ������ �迭�̹Ƿ� �ڽź��� ū ������ �� ĭ�� �ڷ� �Űܾ� �ϹǷ�
            //swap���� ū ������ �ڷ� �ű��
        }
    }
    for (i = 0; i < 10; i++)
        cout << arr[i] << " ";

    return 0;
}