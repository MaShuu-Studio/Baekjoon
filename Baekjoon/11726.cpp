#include <iostream>

using namespace std;

long long save[1001];

long long DP(int n)
{
	if (n == 0) return 1;
	if (n == 1) return 1;

	if (save[n] != 0) return save[n];
	save[n] = (DP(n - 1) + DP(n - 2)) % 10007;
	return save[n]; 

}

int main(void)
{
	int n;
	scanf("%d", &n);

	printf("%d", DP(n));
}