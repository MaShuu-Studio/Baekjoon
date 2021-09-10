#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

queue<pair<int, int>> q;
int n, m;
bool visited[1001][1001];
int tomato[1001][1001];
int answer = 0;

void BFS()
{
	while (!q.empty())
	{
		int qsize = q.size();
		bool added = false;

		for (int i = 0; i < qsize; i++)
		{
			pair<int, int> pos = q.front();

			int x = pos.second;
			int y = pos.first;

			if (x - 1 >= 1 && tomato[y][x - 1] == 0)
			{
				tomato[y][x - 1] = 1;
				q.push({ y, x - 1 });
				added = true;
			}
			if (x + 1 <= m && tomato[y][x + 1] == 0)
			{
				tomato[y][x + 1] = 1;
				q.push({ y, x + 1 });
				added = true;
			}
			if (y - 1 >= 1 && tomato[y - 1][x] == 0)
			{
				tomato[y - 1][x] = 1;
				q.push({ y - 1, x});
				added = true;
			}
			if (y + 1 <= n && tomato[y + 1][x] == 0)
			{
				tomato[y + 1][x] = 1;
				q.push({ y + 1 ,x });
				added = true;
			}
			q.pop();
		}

		if (added) answer++;
	}
}

int main(void)
{
	scanf("%d %d", &m, &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1)
			{
				q.push({ i, j });
				visited[i][j] = true;
			}
		}
	}

	BFS();

	bool fail = false;
	for (int i = 1; i <= n && !fail; i++)
		for (int j = 1; j <= m && !fail; j++)
			if (tomato[i][j] == 0) fail = true;

	printf("%d", fail ? -1 : answer);
}