#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;
int save[1000];
int ans;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		a.push_back(m);
		save[i] = 1;
	}
	ans = save[0];
	for (int i = 1; i < n; i++)
	{
		int max = save[i];
		for (int j = 0; j < i; j++)
		{
			if (a[i] < a[j])
			{
				int val = save[j] + 1;
				if (max < val) max = val;
			}
		}
		if (ans < max) ans = max;
		save[i] = max;
	}

	cout << ans << endl;
}