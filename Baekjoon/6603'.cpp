#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> v;
vector<int> ans;
bool visited[13];

void dfs(int index, int pos)
{
	if ((k - pos + index) < 6) return;
	if (index == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << ans[i] << " ";
		cout << endl;
		return;
	}
	for (int i = pos; i < v.size(); i++)
	{
		if (visited[i]) continue;
		ans.push_back(v[i]);
		visited[i] = true;
		dfs(index + 1, i + 1);
		visited[i] = false;
		ans.pop_back();
	}
}

int main(void)
{
	
	do {
		cin >> k;

		for (int i = 0; i < k; i++)
		{
			int n;
			cin >> n;
			v.push_back(n);
		}

		dfs(0, 0);
		v.clear();
		cout << endl;
	} while (k != 0);
}