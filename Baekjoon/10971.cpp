#include <iostream>

using namespace std;

bool visited[10];
int cost[10][10];
int n;
int start;
int ans = 10000000;

void DFS(int i, int pos, int val)
{
	if (i == n)
	{
		if (cost[pos][start] != 0)
		{
			val += cost[pos][start];
			if (ans > val) ans = val;
		}
		return;
	}

	for (int a = 0; a < n; a++)
	{
		if (a == start) continue;
		if (visited[a]) continue;
		if (cost[pos][a] == 0) continue;

		visited[a] = true;
		int v = val + cost[pos][a];
		if (i == 0)
		{
			start = a;
			v = 0;
		}
		DFS(i + 1, a, v);
		visited[a] = false;
	}
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &cost[i][j]);

	DFS(0, 0, 0);

	printf("%d", ans);
}