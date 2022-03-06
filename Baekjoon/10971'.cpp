#include <iostream>
#include <vector>

using namespace std;

int n;
int w[10][10];
vector<int> v;
bool visited[10];
int ans;

void dfs(int index, int pos)
{
	if (index == n)
	{
		int a = 0;
		if (w[pos][v[0]] == 0) return;

		for (int i = 0; i < n; i++)
		{
			if (i == 0)
				a += w[pos][v[i]];
			else
				a += v[i];
		}

		if (ans > a) ans = a;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (index != 0 && w[pos][i] == 0) continue;
		if (visited[i]) continue;

		if (index == 0)
			v.push_back(i);
		else v.push_back(w[pos][i]);
		visited[i] = true;
		dfs(index + 1, i);
		visited[i] = false;
		v.pop_back();
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];

	ans = 99999999;
	dfs(0, 0);

	cout << ans << endl;
}