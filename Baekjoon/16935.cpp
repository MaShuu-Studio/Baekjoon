#include <iostream>

using namespace std;

int arr[100][100];
int tmp34[100][100];
int tmp56[4][50][50];
int n, m, r;

void arrange(int num)
{
	if (num == 1)
	{
		for (int i = 0; i < n / 2; i++)
			for (int j = 0; j < m; j++)
			{
				int tmp = arr[i][j];
				arr[i][j] = arr[n - 1 - i][j];
				arr[n - 1 - i][j] = tmp;
			}
	}
	else if (num == 2)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m / 2; j++)
			{
				int tmp = arr[i][j];
				arr[i][j] = arr[i][m - 1 - j];
				arr[i][m - 1 - j] = tmp;
			}
	}
	else if (num == 3)
	{
		int tmp = n;
		n = m;
		m = tmp;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				tmp34[i][j] = arr[m - 1 - j][i];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = tmp34[i][j];
	}
	else if (num == 4)
	{
		int tmp = n;
		n = m;
		m = tmp;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				tmp34[i][j] = arr[j][n - 1 - i];
			}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = tmp34[i][j];
	}
	else
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (i < n / 2 && j < m / 2)
				{
					tmp56[0][i][j] = arr[i][j];
				}
				else if (i < n / 2 && j >= m / 2)
				{
					tmp56[1][i][j - m / 2] = arr[i][j];
				}
				else if (i >= n / 2 && j >= m / 2)
				{
					tmp56[2][i - n / 2][j - m / 2] = arr[i][j];
				}
				else if (i >= n / 2 && j < m / 2)
				{
					tmp56[3][i - n / 2][j] = arr[i][j];
				}
			}

		if (num == 5)
		{
			for (int i = 0; i < n / 2; i++)
				for (int j = 0; j < m / 2; j++)
				{
					int ttmp = tmp56[3][i][j];
					tmp56[3][i][j] = tmp56[2][i][j];
					tmp56[2][i][j] = tmp56[1][i][j];
					tmp56[1][i][j] = tmp56[0][i][j];
					tmp56[0][i][j] = ttmp;
				}
		}
		else
		{
			for (int i = 0; i < n / 2; i++)
				for (int j = 0; j < m / 2; j++)
				{
					int ttmp = tmp56[0][i][j];
					tmp56[0][i][j] = tmp56[1][i][j];
					tmp56[1][i][j] = tmp56[2][i][j];
					tmp56[2][i][j] = tmp56[3][i][j];
					tmp56[3][i][j] = ttmp;
				}
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (i < n / 2 && j < m / 2)
				{
					arr[i][j] = tmp56[0][i][j];
				}
				else if (i < n / 2 && j >= m / 2)
				{
					arr[i][j] = tmp56[1][i][j - m / 2];
				}
				else if (i >= n / 2 && j >= m / 2)
				{
					arr[i][j] = tmp56[2][i - n / 2][j - m / 2];
				}
				else if (i >= n / 2 && j < m / 2)
				{
					arr[i][j] = tmp56[3][i - n / 2][j];
				}
			}
	}
}

int main(void)
{
	cin >> n >> m >> r;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < r; i++)
	{
		int a;
		cin >> a;
		arrange(a);
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}