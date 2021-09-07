#include <iostream>

using namespace std;

bool start[21];
int pos;
int status[21][21];

int answer = -1;

int n;

void DFS(int index)
{
	if (index > n / 2)
	{
		int startStat = 0;
		int linkStat = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;
				if (start[i] && start[j]) startStat += status[i][j];
				if (!start[i] && !start[j]) linkStat += status[i][j];
			}
		}

		int ans = abs(startStat - linkStat);
		if (answer > ans || answer == -1) answer = ans;

		return;
	}

	for (int i = pos + 1; i <= n; i++)
	{
		start[i] = true;
		pos = i;
		DFS(index + 1);
		start[i] = false;
	}
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &status[i][j]);

	pos = 1;
	DFS(1);

	printf("%d", answer);
}