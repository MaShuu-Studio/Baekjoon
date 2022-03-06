#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, v;
vector<int> road[1001];

void bfs()
{
	while (true)
	{
		bool empty = q.empty();

		for (int )
	}
}
int main()
{
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
		road[b].push_back(a);
	}
}