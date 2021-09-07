#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
int answerTime = -1;
int n;

int main(void)
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		num.push_back(i);
	}

	do
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", num[i]);
		}
		printf("\n");
	} while (next_permutation(num.begin(), num.end()));
}