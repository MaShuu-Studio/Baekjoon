#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool visited[8];
int arr[8];
vector<int> v;
int n;
int ans = 0;

int sol()
{
	int a = 0;

	for (int i = 1; i < n; i++)
	{
		a += abs(v[i] - v[i - 1]);
	}

	return a;
}

void DFS(int i)
{
	if (i == n)
	{
		int a = sol();
		if (ans < a) ans = a;
		return;
	}

	for (int a = 0; a < n; a++)
	{
		if (visited[a]) continue;

		visited[a] = true;
		v.push_back(arr[a]);
		DFS(i + 1);
		v.pop_back();
		visited[a] = false;
	}
}

int main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	DFS(0);

	printf("%d", ans);
}