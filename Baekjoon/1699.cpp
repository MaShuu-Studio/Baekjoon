#include <iostream>
#include <algorithm>

using namespace std;

int save[100001];
int n;

int main(void)
{
	scanf("%d", &n);

	for (int i = 1; i * i <= n; i++)
		save[i * i] = 1;

	for (int i = 2; i <= n; i++)
	{
		int m = 100000;
		for (int j = 1; j * j <= i; j++)
		{
			m = min(m, save[i - j * j] + 1);
		}
		save[i] = m;
	}

	printf("%d", save[n]);
}