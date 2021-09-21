#include <iostream>

using namespace std;

int save[1000001];
int ans;
int n, T;

#define VALUE 1000000009

int main(void)
{
	scanf("%d", &T);

	save[1] = 1;
	save[2] = 2;
	save[3] = 4;
	int a = 4;

	for (int i = 0; i < T; i++)
	{
		ans = 0;

		scanf("%d", &n);

		for (; a <= n; a++)
			save[a] = ((long long)save[a - 3] + (long long)save[a - 2] + (long long)save[a - 1]) % VALUE;

		printf("%d\n", save[n]);
	}
}