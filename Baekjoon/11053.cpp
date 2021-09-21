#include <iostream>

using namespace std;

int len[1000];
int arr[1000];
int n;
int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	len[0] = 1;
	int ans = 1;
	for (int i = 1; i < n; i++)
	{
		int max = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && len[j] >= max)
				max = len[j] + 1;
		}
		len[i] = max;
		if (max > ans) ans = max;
	}

	printf("%d", ans);
}