#include <iostream>
#include <queue>

using namespace std;

int n;
int l;
int ans;
queue<pair<int, int>> q;
pair<int, int> start, dest;
bool visited[300][300];

void BFS()
{
	while (!q.empty())
	{
		int qsize = q.size();

		for (int i = 0; i < qsize; i++)
		{
			int x = q.front().first;
			int y = q.front().second;

			if (x == dest.first && y == dest.second) return;

			if (x + 2 < l && y + 1 < l && !visited[x + 2][y + 1])
			{
				visited[x + 2][y + 1] = true;
				q.push({ x + 2 , y + 1 });
			}
			if (x + 2 < l && y - 1 >= 0 && !visited[x + 2][y - 1])
			{
				visited[x + 2][y - 1] = true;
				q.push({ x + 2 , y - 1 });
			}
			if (x - 2 >= 0 && y + 1 < l && !visited[x - 2][y + 1])
			{
				visited[x - 2][y + 1] = true;
				q.push({ x - 2 , y + 1 });
			}
			if (x - 2 >= 0 && y - 1 >= 0 && !visited[x - 2][y - 1])
			{
				visited[x - 2][y - 1] = true;
				q.push({ x - 2 , y - 1 });
			}
			if (x + 1 < l && y + 2 < l && !visited[x + 1][y + 2])
			{
				visited[x + 1][y + 2] = true;
				q.push({ x + 1 , y + 2 });
			}
			if (x + 1 < l && y - 2 >= 0 && !visited[x + 1][y - 2])
			{
				visited[x + 1][y - 2] = true;
				q.push({ x + 1 , y - 2 });
			}
			if (x - 1 >= 0 && y + 2 < l && !visited[x - 1][y + 2])
			{
				visited[x - 1][y + 2] = true;
				q.push({ x - 1 , y + 2 });
			}
			if (x - 1 >= 0 && y - 2 >= 0 && !visited[x - 1][y - 2])
			{
				visited[x - 1][y - 2] = true;
				q.push({ x - 1 , y - 2 });
			}
			q.pop();
		}
		ans++;
	}
}

int main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &l);
		scanf("%d %d", &start.first, &start.second);
		scanf("%d %d", &dest.first, &dest.second);

		q.push({ start.first, start.second });
		for (int j = 0; j < 300; j++)
			for (int k = 0; k < 300; k++)
				visited[j][k] = false;
		visited[start.first][start.second] = true;
		BFS();

		printf("%d\n", ans);
		ans = 0;
		while (!q.empty()) q.pop();
	}
}