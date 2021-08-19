#include <iostream>

using namespace std;

int n, m;
int val[9] = { 0 };

void DFS(int index)
{
	if (index > m)
	{
		for (int i = 1; i <= m; i++)
		{
			printf("%d ", val[i]);
		}
		printf("\n");
		return;
	}

	val[index] = 0;
	while (val[index] < n)
	{
		val[index]++;
		DFS(index + 1);
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);

	DFS(1);
}