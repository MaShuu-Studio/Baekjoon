#include<iostream>

int arr[1001][1001];
int h, w, x, y;

void restore(int i)
{
	if (i > h) return;

	for (int j = 1 + y; j <= w; j++)
	{
		arr[i][j] -= arr[i - x][j - y];
	}
	restore(i + 1);
}

int main(void)
{
	scanf("%d %d %d %d", &h, &w, &x, &y);

	for (int i = 1; i <= h + x; i++)
		for (int j = 1; j <= w + y; j++)
			scanf("%d", &arr[i][j]);

	restore(x + 1);
	
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}