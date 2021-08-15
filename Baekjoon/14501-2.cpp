#include <iostream>

using namespace std;

pair<int, int> sals[15];
int day;
int ans;

void DFS(int i, int val)
{
	if (i > day - 1)
	{
		ans = max(ans, val);
		return;
	}
	
	DFS(i + sals[i].first, sals[i].second + val);
	DFS(i + 1, val);
}

int main(void)
{
	scanf("%d", &day);

	for (int i = 0; i < day; i++)
	{
		scanf("%d %d", &sals[i].first, &sals[i].second);

		if (day - i < sals[i].first)
			sals[i].second = 0;
	}

	DFS(0, 0);

	printf("%d", ans);
}
