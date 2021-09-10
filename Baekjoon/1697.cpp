#include <iostream>
#include <queue>

using namespace std;

bool visited[100001];
queue<int> q;
int n, k;
int answer;

void BFS()
{
	while (!q.empty())
	{
		int qsize = q.size();
		bool finded = false;

		for (int i = 0; i < qsize; i++)
		{
			int pos = q.front();
			if (pos == k)
			{
				finded = true;
				break;
			}

			if (pos - 1 >= 0 && visited[pos - 1] == false)
			{
				q.push(pos - 1);
				visited[pos - 1] = true;
			}
			
			if (pos + 1 <= 100000 && visited[pos + 1] == false)
			{
				q.push(pos + 1);
				visited[pos + 1] = true;
			}

			if (pos * 2 <= 100000 && visited[pos * 2] == false)
			{
				q.push(pos * 2);
				visited[pos * 2] = true;
			}

			q.pop();
		}

		if (finded) break;
		answer++;
	}
}

int main(void)
{
	scanf("%d %d", &n, &k);

	visited[n] = true;
	q.push(n);

	BFS();

	printf("%d", answer);
}