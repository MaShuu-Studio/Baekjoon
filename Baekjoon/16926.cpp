#include <iostream>

using namespace std;

int arr[301][301];
int n, m, r;
int maxdepth;

void rotate(int depth, int i, int j)
{
	if (depth > maxdepth) return;

	int start = arr[depth][depth];

	for (; j <= m - depth; j++)
	{
		arr[i][j] = arr[i][j + 1];
	}

	for (; i <= n - depth; i++)
	{
		arr[i][j] = arr[i + 1][j];
	}

	for (; j >= depth + 1; j--)
	{
		arr[i][j] = arr[i][j - 1];
	}

	for (; i > depth + 1; i--)
	{
		arr[i][j] = arr[i - 1][j];
	}
	arr[i][j] = start;

	depth++;

	rotate(depth, depth, depth);
}

int main(void)
{
	scanf("%d %d %d", &n, &m, &r);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			int num = 0;
			scanf("%d", &num);
			arr[i][j] = num;
		}

	//r = r % (2 * (n - 1 + m - 1));
	maxdepth = min(n, m) / 2;

	for (int i = 0 ;i < r; i++)
		rotate(1, 1, 1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}