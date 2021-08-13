#include <iostream>

int compare(const void* a, const void* b)
{
	const int n = *(int*)a;
	const int m = *(int*)b;

	int val = 0;
	if (n > m) val = 1;
	else if (n < m) val = -1;
	return val;
}

int main()
{
	int mans[9] = { 0 };
	int total = 0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &mans[i]);
		total += mans[i];
	}

	qsort(mans, 9, sizeof(int), compare);

	for (int i = 0; i < 9; i++)
	{
		int t = total;
		int j = i;
		for (; j < 9; j++)
		{
			t -= (mans[i] + mans[j]);
			if (t != 100) t = total;
			else break;
		}

		if (t == 100)
		{
			mans[i] = -1;
			mans[j] = -1;
			break;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (mans[i] == -1) continue;
		printf("%d\n", mans[i]);
	}
}