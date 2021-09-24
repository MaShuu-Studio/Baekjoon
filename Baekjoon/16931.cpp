#include <iostream>

using namespace std;

int n, m;
int amt;
int box[100][100];
int area;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> box[i][j];

	// 위, 아래
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			area += 2;
	// 왼쪽
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (j == 0)
				area += box[i][j];
			else if (box[i][j] > box[i][j - 1])
				area += box[i][j] - box[i][j-1];
		}
	}

	// 오른쪽
	for (int j = m - 1; j >= 0; j--)
	{
		for (int i = 0; i < n; i++)
		{
			if (j == m - 1)
				area += box[i][j];
			else if (box[i][j] > box[i][j + 1])
				area += box[i][j] - box[i][j + 1];
		}
	}

	// 뒤쪽
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0)
				area += box[i][j];
			else if (box[i][j] > box[i - 1][j])
				area += box[i][j] - box[i - 1][j];
		}
	}

	// 앞쪽
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == n - 1)
				area += box[i][j];
			else if (box[i][j] > box[i + 1][j])
				area += box[i][j] - box[i + 1][j];
		}
	}

	cout << area;
}