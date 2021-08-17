#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	int n;
	list<int> l;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char s[100] = { 0 };
		scanf("%s", s);

		string str = string(s);
		if (str == "pop_front")
		{
			if (l.empty()) printf("-1\n");
			else
			{
				printf("%d\n",l.front());
				l.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (l.empty()) printf("-1\n");
			else
			{
				printf("%d\n", l.back());
				l.pop_back();
			}
		}
		else if (str == "size")
		{
			printf("%d\n", l.size());
		}
		else if (str == "empty")
		{
			printf("%d\n", l.empty() ? 1 : 0);
		}
		else if (str == "front")
		{
			if (l.empty()) printf("-1\n");
			else
			{
				printf("%d\n", l.front());
			}
		}
		else if (str == "back")
		{
			if (l.empty()) printf("-1\n");
			else
			{
				printf("%d\n", l.back());
			}
		}
		else if (str == "push_back")
		{
			int num;
			scanf("%d", &num);
			l.push_back(num);
		}
		else
		{
			int num;
			scanf("%d", &num);
			l.push_front(num);
		}
	}
}