#include <iostream>
#include <queue>

using namespace std;

bool visited[300][300];
queue<pair<int, int>> q;
int s;
int sx, sy, dx, dy;
int ans;

void BFS()
{
	q.push(pair(sy, sx));

	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			pair<int, int> f = q.front();
			int y = f.first;
			int x = f.second;
			q.pop();

			if (x == dx && y == dy)
				return;

			int px, py;

			px = x - 2;
			py = y - 1;

			if (px >= 0 && py >= 0 && visited[py][px] == false)
			{
				visited[py][px] = true;
				q.push(pair(py, px));
			}

			px = x - 2;
			py = y + 1;

			if (px >= 0 && py < s && visited[py][px] == false)
			{
				visited[py][px] = true;
				q.push(pair(py, px));
			}
			px = x + 2;
			py = y - 1;

			if (px < s && py >= 0 && visited[py][px] == false)
			{
				visited[py][px] = true;
				q.push(pair(py, px));
			}
			px = x + 2;
			py = y + 1;

			if (px < s && py < s && visited[py][px] == false)
			{
				visited[py][px] = true;
				q.push(pair(py, px));
			}
			
			px = x - 1;
			py = y - 2;

			if (px >= 0 && py >= 0 && visited[py][px] == false)
			{
				visited[py][px] = true;
				q.push(pair(py, px));
			}

			px = x - 1;
			py = y + 2;

			if (px >= 0 && py < s && visited[py][px] == false)
			{
				visited[py][px] = true;
				q.push(pair(py, px));
			}
			px = x + 1;
			py = y - 2;

			if (px < s && py >= 0 && visited[py][px] == false)
			{
				visited[py][px] = true;
				q.push(pair(py, px));
			}
			px = x + 1;
			py = y + 2;

			if (px < s && py < s && visited[py][px] == false)
			{
				visited[py][px] = true;
				q.push(pair(py, px));
			}

		}

		ans++;
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		cin >> sx >> sy;
		cin >> dx >> dy;

		ans = 0;

		while (!q.empty())
		{
			q.pop();
		}

		for (int j = 0; j < s; j++)
			for (int k = 0; k < s; k++)
			{
				visited[j][k] = false;
			}

		BFS();
		cout << ans << endl;
	}
}