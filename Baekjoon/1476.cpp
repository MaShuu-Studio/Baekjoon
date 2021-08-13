#include <iostream>

int main(void)
{
	int a = 1, b = 1, c = 1;
	int day = 1;
	int e, s, m;

	scanf("%d %d %d", &e, &s, &m);

	while (true)
	{
		if (a == e && b == s && c == m) break;

		day++;
		a++; b++; c++;

		if (a > 15) a = 1;
		if (b > 28) b = 1;
		if (c > 19) c = 1;
	}

	printf("%d", day);
}