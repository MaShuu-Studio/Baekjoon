#include <iostream>

int main(void)
{
	int n;
	char board[50][50] = { 0 };
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
		{
			char c = getchar();
			if (c == '\n')
			{
				j--;
				continue;
			}
			board[i][j] = c;
		}

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char start = board[i][j];
			int total = 1;
			bool changed = false;

			char newBoard[50][50] = { 0 };
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					newBoard[i][j] = board[i][j];

			// 위방향 이동
			for (int k = i - 1; k >= 0; k--)
			{
				if (newBoard[k][j] == start) total++;
				else if (changed == false)
				{
					char tmp = newBoard[k][j];
					// 왼쪽 체크
					if (j > 0 && newBoard[k][j - 1] == start)
					{
						newBoard[k][j] = newBoard[k][j - 1];
						newBoard[k][j - 1] = tmp;
						total++;
					}
					// 오른쪽 체크
					else if (j < n - 1 && newBoard[k][j + 1] == start)
					{
						newBoard[k][j] = newBoard[k][j + 1];
						newBoard[k][j + 1] = tmp;
						total++;
					}
					// 위쪽 체크
					else if (k > 0 && newBoard[k - 1][j] == start)
					{
						newBoard[k][j] = newBoard[k - 1][j];
						newBoard[k - 1][j] = tmp;
						total++;
					}
					else break;
					changed = true;
				}
				else break;
			}

			if (total > max) max = total;

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					newBoard[i][j] = board[i][j];
			total = 1;
			changed = false;

			// 아래방향 이동
			for (int k = i + 1; k < n; k++)
			{
				if (newBoard[k][j] == start) total++;
				else if (changed == false)
				{
					char tmp = newBoard[k][j];
					// 왼쪽 체크
					if (j > 0 && newBoard[k][j - 1] == start)
					{
						newBoard[k][j] = newBoard[k][j - 1];
						newBoard[k][j - 1] = tmp;
						total++;
					}
					// 오른쪽 체크
					else if (j < n - 1 && newBoard[k][j + 1] == start)
					{
						newBoard[k][j] = newBoard[k][j + 1];
						newBoard[k][j + 1] = tmp;
						total++;
					}
					// 아래쪽 체크
					else if (k < n - 1 && newBoard[k + 1][j] == start)
					{
						newBoard[k][j] = newBoard[k + 1][j];
						newBoard[k + 1][j] = tmp;
						total++;
					}
					else break;
					changed = true;
				}
				else break;
			}

			if (total > max) max = total;

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					newBoard[i][j] = board[i][j];
			total = 1;
			changed = false;

			// 오른쪽 방향 이동
			for (int k = j + 1; k < n; k++)
			{
				if (newBoard[i][k] == start) total++;
				else if (changed == false)
				{
					char tmp = newBoard[i][k];
					// 위쪽 체크
					if (i > 0 && newBoard[i - 1][k] == start)
					{
						newBoard[i][k] = newBoard[i - 1][k];
						newBoard[i - 1][k] = tmp;
						total++;
					}
					// 아래쪽 체크
					else if (i < n - 1 && newBoard[i + 1][k] == start)
					{
						newBoard[i][k] = newBoard[i + 1][k];
						newBoard[i + 1][k] = tmp;
						total++;
					}
					// 오른쪽 체크
					else if (k < n - 1 && newBoard[i][k + 1] == start)
					{
						newBoard[i][k] = newBoard[i][k + 1];
						newBoard[i][k + 1] = tmp;
						total++;
					}
					else break;
					changed = true;
				}
				else break;
			}

			if (total > max) max = total;

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					newBoard[i][j] = board[i][j];
			total = 1;
			changed = false;

			// 왼쪽 방향 이동
			for (int k = j - 1; k >= 0; k--)
			{
				if (newBoard[i][k] == start) total++;
				else if (changed == false)
				{
					char tmp = newBoard[i][k];
					// 위쪽 체크
					if (i > 0 && newBoard[i - 1][k] == start)
					{
						newBoard[i][k] = newBoard[i - 1][k];
						newBoard[i - 1][k] = tmp;
						total++;
					}
					// 아래쪽 체크
					else if (i < n - 1 && newBoard[i + 1][k] == start)
					{
						newBoard[i][k] = newBoard[i + 1][k];
						newBoard[i + 1][k] = tmp;
						total++;
					}
					// 왼쪽 체크
					else if (k > 0 && newBoard[i][k - 1] == start)
					{
						newBoard[i][k] = newBoard[i][k - 1];
						newBoard[i][k - 1] = tmp;
						total++;
					}
					else break;
					changed = true;
				}
				else break;
			}

			if (total > max) max = total;

			if (max >= n) break;
		}
		if (max >= n) break;
	}

	printf("%d", max);
}