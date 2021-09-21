#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> road[1001];
bool visited[1001];
int ans;

void DFS(int pos)
{
	visited[pos] = true;

	for (int i = 0; i < road[pos].size(); i++)
	{
		int dest = road[pos][i];
		if (visited[dest] == false)
			DFS(dest);
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		road[a].push_back(b);
		road[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i]) continue;
		DFS(i);
		ans++;
	}

	printf("%d", ans);
}