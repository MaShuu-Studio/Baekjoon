#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	int n;
	queue<int> q;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char s[100] = { 0 };
		scanf("%s", s);
		
		string str = string(s);
		
		if (str == "pop")
		{
			if (q.empty()) printf("-1\n");
			else
			{
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if (str == "size")
		{
			printf("%d\n", q.size());
		}
		else if (str == "empty")
		{
			printf("%d\n", q.empty() ? 1 : 0);
		}
		else if (str == "front")
		{
			if (q.empty()) printf("-1\n");
			else
			{
				printf("%d\n", q.front());
			}
		}
		else if (str == "back")
		{
			if (q.empty()) printf("-1\n");
			else
			{
				printf("%d\n", q.back());
			}
		}
		else
		{
			int num;
			scanf("%d", &num);
			q.push(num);
		}
	}
}