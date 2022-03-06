#include <iostream>
#include <vector>

using namespace std;

int n, s;
vector<int> v;
bool visited[20];
int ans;

void dfs(int index, int pos, int val)
{
	if (val == s) ans++;

	for (int i = pos; i < n; i++)
	{
		if (visited[i]) continue;

		visited[i] = true;
		dfs(index + 1, i + 1, val + v[i]);
		visited[i] = false;
	}
}

int main(void)
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		v.push_back(m);
	}

	dfs(0, 0, 0);
	if (s == 0) ans--;

	cout << ans << endl;
}