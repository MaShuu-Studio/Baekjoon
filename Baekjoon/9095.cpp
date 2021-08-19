#include <iostream>

using namespace std;

int fac(int n)
{
	if (n <= 1) return 1;
	n *= fac(n - 1);
	return n;
}

int P(int n1, int n2, int n3)
{
	int nfac = fac(n1 + n2 + n3);

	return nfac / (fac(n1) * fac(n2) * fac(n3));
}

int main(void)
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int n;
		int ans = 0;
		scanf("%d", &n);

		for (int j = 0; j <= n / 2; j++)
		{
			int amt[4] = { 0, n - 2 * j, j, 0 };
			while (true)
			{
				ans += P(amt[1], amt[2], amt[3]);
				amt[3] += 1;
				amt[1] -= 3;
				if (amt[1] < 0) break;
			}
		}

		printf("%d\n", ans);
	}
}