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

	int ans = save[0] = 1;

	for (int i = 0; i < n; i++)
	{
		int max = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j] && save[j] >= max) max = save[j] + 1;
		}
		if (max > ans) ans = max;
		save[i] = max;
	}

	printf("%d", ans);
}