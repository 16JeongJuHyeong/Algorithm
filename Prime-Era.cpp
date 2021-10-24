#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];

void Prime(int N)
{
	for (int i=2; i <= N; i++) //arr[2] = 2 arr[4]=4 ... arr[99999] = 99999
		arr[i] = i;
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] != 0)
			for (int j = 2 * i; j <= N; j += i)
				arr[j] = 0;
	}
	for (int i = 2; i <= N; i++)
		if (arr[i] != 0)
			cout << arr[i] << " ";
}

int main()
{
	int N;
	cin >> N;
	Prime(N);
	return 0;
}