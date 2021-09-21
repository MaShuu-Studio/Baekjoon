#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;
vector<int> road[1001];
vector<int> dfsroad;
vector<int> bfsroad;
bool visited[1001];
queue<int> q;

void DFS(int pos)
{
	visited[pos] = true;

	for (int i = 0; i < road[pos].size(); i++)
	{
		int dest = road[pos][i];
		if (visited[dest] == false)
		{
			dfsroad.push_back(dest);
			DFS(dest);
		}
	}
}

void BFS(int start)
{
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int qsize = q.size();

		for (int i = 0; i < qsize; i++)
		{
			int pos = q.front();

			for (int j = 0; j < road[pos].size(); j++)
			{
				int dest = road[pos][j];
				if (visited[dest] == false)
				{
					bfsroad.push_back(dest);
					visited[dest] = true;
					q.push(dest);
				}
			}
			q.pop();
		}
	}
}

int main(void)
{
	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		road[a].push_back(b);
		road[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++)
		sort(road[i].begin(), road[i].end());

	dfsroad.push_back(v);
	bfsroad.push_back(v);

	visited[v] = true;
	DFS(v);
	for (int i = 1; i <= n; i++)
		visited[i] = false;
	
	BFS(v);

	for (int i = 0; i < dfsroad.size(); i++)
	{
		printf("%d ", dfsroad[i]);
	}
	printf("\n");
	for (int i = 0; i < bfsroad.size(); i++)
	{
		printf("%d ", bfsroad[i]);
	}
	printf("\n");
}