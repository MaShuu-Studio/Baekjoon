#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> v;
vector<int> order;
bool visited[8];
int ans = 0;

void find(int index)
{
	if (index == n)
	{
		int a = 0;
		for (int i = 0; i < n - 1; i++)
		{
			a += abs(order[i] - order[i + 1]);
		}
		if (a > ans) ans = a;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i]) continue;

		visited[i] = true;
		order.push_back(v[i]);
		find(index + 1);
		order.pop_back();
		visited[i] = false;
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		v.push_back(m);
	}

	find(0);
	cout << ans << endl;
}