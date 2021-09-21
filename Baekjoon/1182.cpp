#include<iostream>

using namespace std;

int n;
int s;
int arr[20];
bool visited[20];
int ans;

void DFS(int i, int c, int val)
{
	if (val == s) ans++;

	for (int a = c; a < n; a++)
	{
		if (visited[a]) continue;

		visited[a] = true;
		DFS(i + 1, a + 1, val + arr[a]);
		visited[a] = false;
	}
}

int main(void)
{
	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	DFS(0, 0, 0);
	if (s == 0) ans--;
	printf("%d", ans);
}