#include <iostream>

using namespace std;

int n, m;
int cand[9] = { 0 };
int val[9] = { 0 };

void DFS(int index)
{
	if (index > m)
	{
		for (int i = 1; i <= m; i++)
		{
			printf("%d ", val[i]);
		}
		printf("\n");
		return;
	}

	bool skip;
	int j = 0;
	val[index] = cand[j];
	while (val[index] < cand[n])
	{
		skip = false;
		val[index] = cand[++j];

		for (int i = 1; i < index; i++)
			if (val[index] == val[i]) skip = true;

		if (skip == false)
			DFS(index + 1);
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%d", &cand[i]);

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			if (cand[i] > cand[j])
			{
				int tmp = cand[i];
				cand[i] = cand[j];
				cand[j] = tmp;
			}

	DFS(1);
}