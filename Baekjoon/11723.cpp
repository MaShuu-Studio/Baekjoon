#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int amount;
	vector<int> s;

	scanf("%d", &amount);

	for (int i = 0; i < amount; i++)
	{
		char type[10] = { 0 };
		int x;
		scanf("%s %d", type, &x);

		auto it = find(s.begin(), s.end(), x);
		bool exist = it != s.end();

		if (strcmp(type, "add") == 0)
		{
			if (exist == false) s.push_back(x);
		}
		else if (strcmp(type, "remove") == 0)
		{
			if (exist) s.erase(it);
		}
		else if (strcmp(type, "check") == 0)
		{
			if (exist) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(type, "toggle") == 0)
		{
			if (exist) s.erase(it);
			else s.push_back(x);
		}
		else if (strcmp(type, "all") == 0)
		{
			s.erase(s.begin(), s.end());
			for (int i = 1; i <= 20; i++)
				s.push_back(i);
		}
		else if (strcmp(type, "empty") == 0)
		{
			s.erase(s.begin(), s.end());
		}
	}
}