#include <iostream>

using namespace std;

long long end1[100001];
long long end2[100001];
long long end3[100001];
int t;
int n;

const int overflow = 1000000009;

int main(void)
{
	end1[1] = 1;
	end2[2] = 1;
	end2[2] = 1;
	end1[3] = 1;
	end2[3] = 1;
	end3[3] = 1;

	for (int i = 4; i <= 100000; i++)
	{
		end1[i] = (end2[i - 1] + end3[i - 1]) % overflow;
		end2[i] = (end1[i - 2] + end3[i - 2]) % overflow;
		end3[i] = (end1[i - 3] + end2[i - 3]) % overflow;
	}

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);

		printf("%d\n", ((end1[n] + end2[n]) % overflow + end3[n]) % overflow);
	}
}