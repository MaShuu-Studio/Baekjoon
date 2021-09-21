#include <iostream>

using namespace std;

int n;
int arr[100000];
int save[100000];

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	save[0] = arr[0];
	int ans = arr[0];

	for (int i = 1; i < n; i++)
	{
		int val = save[i - 1];
		if (val > 0) save[i] = val + arr[i];
		else save[i] = arr[i];
		if (save[i] > ans) ans = save[i];
	}

	printf("%d", ans);
}