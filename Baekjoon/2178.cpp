#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

queue<pair<int, int>> q;
int n, m;
bool visited[101][101];
int maze[101][101];
int answer = 1;

void BFS()
{
	q.push({ 1,1 });
	visited[1][1] = true;

	while (!q.empty())
	{
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			pair<int, int> pos = q.front();
			int x = pos.first;
			int y = pos.second;

			if (x - 1 >= 1 && maze[y][x - 1] != 0 && visited[y][x - 1] == false)
			{
				q.push({ x - 1,y });
				visited[y][x - 1] = true;
			}
			
			if (x + 1 <= m && maze[y][x + 1] != 0 && visited[y][x + 1] == false)
			{
				q.push({ x + 1,y });
				visited[y][x + 1] = true;
			}
			
			if (y - 1 >= 1 && maze[y - 1][x] != 0 && visited[y - 1][x] == false)
			{
				q.push({ x,y - 1 });
				visited[y - 1][x] = true;
			}
			
			if (y + 1 <= n && maze[y + 1][x] != 0 && visited[y + 1][x] == false)
			{
				q.push({ x,y + 1 });
				visited[y + 1][x] = true;
			}
			q.pop();
		}
		answer++;

		if (visited[n][m]) break;
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		char s[100];
		scanf("%s", s);
		for (int j = 1; j <= m; j++)
			maze[i][j] = s[j - 1] - '0';
	}

	BFS();

	printf("%d", answer);
}