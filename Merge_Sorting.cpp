#include <iostream>
using namespace std;

int sorted[8]; // ���� �迭�� �ݵ�� ���� ����
//�ٸ� �Լ��鿡�� ���� �迭 ���纻�� �����ϴ� ��ȿ���� �ൿ�� ���� ����

void merge(int* arr, int m, int middle, int n)
{// �� �迭�� ���ĳ����� ����
    int left_arr_idx = m; //�� �迭 �� ���� �迭
    int right_arr_idx = middle + 1; // �� �迭 �� ������ �迭
    //�迭�� ������ �ؼ� ������ ������ �ִ� ��ó�� ��������
    //������ �迭�� ���ӵ� �޸� ������ �Ҵ�ǹǷ� ��� ������ �迭�� ���� �迭 �ٷ� �����̴�
    int final_arr_idx = m;


    //�⺻���� ������ �� �迭(���ظ� ���� ���� ����� �� �迭���� �ִٰ� ����)�� �ִٸ�
    //�� �� ���� ���ʰ��� ���� ���� �����̴� ( ������ ������ �ƴٰ� ����)
    //�� ���� ���� ���� ���� ���� ��ĥ �迭�� ù��° ĭ ���� �ְ�,
    //�Ű��� ������ ū ���� �ٸ� ���� ���� ���Ѵ�. �� �۾��� �ݺ���
    //���ĵ� ���� �� �迭�� ����
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
    //������ �� �迭�� ���� �ϳ��� �� �� �迭�� �־���.
    //��쿡 ���� ���� �迭�� ���� ���� �� �����ٸ�, ������ �迭�� ���� ���� ������
    //���� ������ �� �迭�� ��� �־��ش�
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
{ //�迭�� ���� �ɰ��� ���� �۾�
    if (m < n)
    {
        //m�� n���� ũ�ų� ���ٴ� �� ù��° �迭 �ε����� ������ �ε����� ���ų� ũ�ٴ� �ǵ�
        //�׷� �迭�� �ϳ���� ���̹Ƿ� ���� �� ����
        int middle = (m + n) / 2; //�����ϰ� �߰��� ������
        mergeSort(arr, m, middle); //����Լ��� �θ��� ���� �迭�� �ٽ� ������ ������
        mergeSort(arr, middle + 1, n);
        merge(arr, m, middle, n);
        //���� ȣ��� �� �Լ����� merge�� �ϱ� ������ ���� �迭�� merge�� ���߿� ����Ǿ�
        //���������� ������ ��ģ��
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