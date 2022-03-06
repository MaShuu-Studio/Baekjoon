#include <iostream>
#include <vector>
using namespace std;

int n;
int ans;
int save[1000];
vector<int> v;

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		v.push_back(m);
		save[i] = m;
	}

	ans = save[0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[j] < v[i])
			{
				int m = v[i] + save[j];
				if (save[i] < m) save[i] = m;
			}				
		}
		if (ans < save[i]) ans = save[i];
	}

	cout << ans << endl;
}