#include <iostream>

using namespace std;

int n;
int save[1001];

int dp(int index)
{
	if (save[index] != 0) return save[index];
	save[index] = (dp(index - 1) + dp(index - 2) * 2) % 10007ll;
	return save[index];
}

int main(void)
{
	cin >> n;

	save[1] = 1;
	save[2] = 3;

	cout << dp(n);
}