#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[26][26];
int house[26][26];
int pos = 0;
vector<int> amount;
int n;

void DFS(int i, int j)
{
	if (i < 1 || j < 1 || i > n || j > n) return;
	if (house[i][j] == 0) return;
	if (visited[i][j]) return;

	visited[i][j] = true;
	amount[pos]++;

	DFS(i + 1, j);
	DFS(i - 1, j);
	DFS(i, j + 1);
	DFS(i, j - 1);
}

int main(void)
{
	scanf("%d", &n);

	int i = 1;

	for (int i = 1; i <= n; i++)
	{
		char c[26];

		scanf("%s", c);

		for (int j = 1; j <= n; j++)
			house[i][j] = c[j - 1] - '0';
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (house[i][j] != 0 && visited[i][j] == false)
			{
				amount.push_back(0);
				DFS(i, j);
				pos++;
			}

	sort(amount.begin(), amount.end());

	printf("%d\n", amount.size());
	for (int i = 0; i < amount.size(); i++)
		printf("%d\n", amount[i]);
}