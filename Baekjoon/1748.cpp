#include <iostream>

using namespace std;

int main(void)
{
	int n;

	scanf("%d", &n);

	int ntmp = n;
	int amount = 9;
	int progress = 1;
	int d = 1;
	int ans = 0;

	while (true)
	{
		ntmp /= 10;

		if (ntmp > 0)
		{
			ans += d * amount;
			d += 1;
			progress *= 10;
			amount *= 10;
		}
		else
		{
			ans += d * (n - (progress - 1));
			break;
		}
	}

	printf("%d", ans);
}