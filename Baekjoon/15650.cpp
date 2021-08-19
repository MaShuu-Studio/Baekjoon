#include <iostream>

using namespace std;

int n, m;
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
	val[index] = 0;
	while (val[index] < n)
	{
		skip = false;
		val[index]++;
		for (int i = 1; i < index; i++)
			if (val[index] <= val[i]) skip = true;
		if (skip == false)
			DFS(index + 1);
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);

	DFS(1);
}