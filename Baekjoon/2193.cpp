#include <iostream>

using namespace std;

long long save[91];


long long DP(int index)
{
	if (index == 1) return 1;
	if (index == 2) return 1;
	if (save[index] != 0) return save[index];

	save[index] = DP(index - 1) + DP(index - 2);

	return save[index];
}

int main(void)
{
	int n;
	scanf("%d", &n);

	printf("%lld", DP(n));
}