#include <iostream>
#include <cmath>

using namespace std;

bool visited[10];
int arr[10];
char str[10];
int n;
long long maxv = 0;
long long minv = 9999999999;

void DFS(int i)
{
	if (i > n)
	{
		long long val = 0;
		for (int i = 0; i <= n; i++)
		{
			val += arr[i] * (long long)pow(10, n - i);
		}
		if (val > maxv) maxv = val;
		if (val < minv) minv = val;
		return;
	}

	int pos = 9;

	for (int a = pos; a >= 0; a--)
	{
		if (visited[a]) continue;
		if (i != 0)
		{
			if (str[i] == '<' && arr[i - 1] > a) continue;
			else if (str[i] == '>' && arr[i - 1] < a) continue;
		}

		visited[a] = true;
		arr[i] = a;
		DFS(i + 1);
		visited[a] = false;
	}
}

int main(void)
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		cin >> str[i];
	}

	DFS(0);

	int mxarr[10] = { 0 };
	int mnarr[10] = { 0 };

	for (int i = n; i >= 0; i--)
	{
		mxarr[i] = maxv % 10;
		mnarr[i] = minv % 10;

		maxv /= 10;
		minv /= 10;
	}

	for (int i = 0; i <= n; i++)
		printf("%d", mxarr[i]);
	printf("\n");
	for (int i = 0; i <= n; i++)
		printf("%d", mnarr[i]);

	printf("\n");

}

