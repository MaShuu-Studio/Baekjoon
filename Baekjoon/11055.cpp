#include <iostream>

using namespace std;

int save[1000];
int arr[1000];
int n;

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = save[0] = arr[0];

	for (int i = 1; i < n; i++)
	{
		int max = arr[i];
		for (int j = 0; j < i; j++)
		{
			int val = save[j] + arr[i];
			if (arr[i] > arr[j] && val > max) max = val;
		}
		if (max > ans) ans = max;
		save[i] = max;
	}

	printf("%d", ans);
}