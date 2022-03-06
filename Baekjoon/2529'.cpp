#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<char> str;
vector<int> v;
bool visited[10];
bool needzero[2];
long long ans[2];

void dfs(int index)
{
	if (index == str.size() + 1)
	{
		long long a = 0;
		bool b = false;
		for (int i = v.size() - 1; i >= 0; i--)
		{
			a += (long long)v[i] * pow(10, v.size() - 1 - i);
			if (i == 0 && v[i] == 0) b = true;
		}
		if (ans[0] < a)
		{
			if (b) needzero[0] = true;
			else needzero[0] = false;
			ans[0] = a;
		}
		if (ans[1] > a)
		{
			if (b) needzero[1] = true;
			else needzero[1] = false;
			ans[1] = a;
		}
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (visited[i])
			continue;
		if (index > 0)
		{
			if ((str[index - 1] == '<' && v[index - 1] >= i)
				|| (str[index - 1] == '>' && v[index - 1] <= i)) continue;
		}
		v.push_back(i);
		visited[i] = true;
		dfs(index + 1);
		v.pop_back();
		visited[i] = false;
	}
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		str.push_back(c);
	}

	ans[0] = 0;
	ans[1] = 9999999999ll;

	dfs(0);

	cout << (needzero[0] ? "0" : "") << ans[0] << endl;
	cout << (needzero[1] ? "0" : "") << ans[1] << endl;
}