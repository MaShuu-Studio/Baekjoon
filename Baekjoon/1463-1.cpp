#include<iostream>
#include<queue>

using namespace std;

int ans = 0;
queue<int> q;

void BFS(int num)
{
	if (num == 1) return;

	bool find = false;
	q.push(num);

	while (!find)
	{
		int qsize = q.size();

		for (int i = 0; i < qsize; i++)
		{
			int n = q.front();
			int tmp;

			if (n % 3 == 0)
			{
				tmp = n / 3;
				if (tmp == 1) find = true;
				q.push(tmp);
			}

			if (n % 2 == 0)
			{
				tmp = n >> 1;
				if (tmp == 1) find = true;
				q.push(tmp);
			}

			{
				tmp = n - 1;
				if (tmp == 1) find = true;
				q.push(tmp);
			}

			q.pop();
		}
		ans++;
	}
}

int main(void)
{
	int num;

	scanf("%d", &num);

	BFS(num);

	printf("%d", ans);
}