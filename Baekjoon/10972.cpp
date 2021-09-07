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
		int tmp;
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	
	if (next_permutation(num.begin(), num.end()) == false) printf("-1");
	else
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", num[i]);
		}
	}
}