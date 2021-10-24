#include <iostream>
using namespace std;

int arr[5] = { 7,4,9,2,5};

void quicksorting(int* data, int start, int end)
{
    int temp;
    if (start >= end)   //���Ұ� 1���� ��� -> �ƹ��͵� ����
    {
        return;
    }
    int pivot = start;
    int left_index = start; // �ǹ����� ū ���� ���� ���� �ε���
    int right_index = end; // �ǹ����� ���� ���� ���� ������ �ε���
    while (left_index < right_index)
    {
        // �������� : ��-������ �ε����� �ǹ� ���� '���Ƶ� �ѱ��' �۰ų� ū ���� ã�ƾ� �Ѵ�
        // Ž�� �� �ǹ� ��, ���� �ε���, ������ �ε����� ��� ������ ���ѷ����� ����
        // �׸��� ������ ���� ���� �Ѱ� ū�� , ���� ���� �� ã����( ex.��� ���� ���� ��� ) �ǹ����� �����ϰ�
        // ��-���� �����ؼ� �����͸� �ϳ��� �ٿ������� �ȴ�
        while ((arr[left_index] <= arr[pivot]) && left_index <= end) left_index++; //�ǹ����� ū ���� ã�� Ž��
        while (arr[right_index] >= arr[pivot] && right_index > start) right_index--; //�ǹ����� ���� ���� ã�� Ž��
        if (left_index < right_index) // Ž���ؼ� �ε��� �� ��ȯ�� ����, �ٵ� ���� �ε����� ������ �ε����� �����ϸ� �� ��
        {
            temp = arr[right_index];
            arr[right_index] = arr[left_index];
            arr[left_index] = temp;
        }
    }
    //�ݺ����� ���Դٴ� �� ���� �ε����� �� ũ�ٴ� ���̹Ƿ� �ǹ� �����Ϳ� ��ȯ
    if (left_index >= right_index)
    {
        temp = arr[pivot];
        arr[pivot] = arr[right_index];
        arr[right_index] = temp;
    }
    //���ο� �ǹ� �� ���� ����, ���� ����
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