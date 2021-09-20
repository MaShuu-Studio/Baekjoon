#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool visited[13];
vector<int> val;
vector<int> v;
int n;

void DFS(int i, int pos)
{
	if (i == 6)
	{
		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}


	for (int a = pos; a < n; a++)
	{
		if (n - a < 6 - i) break;
		if (visited[a]) continue;

		visited[a] = true;
		v.push_back(val[a]);
		DFS(i + 1, a);
		v.pop_back();
		visited[a] = false;
	}
}

int main() 
{
	while (true)
	{
		scanf("%d", &n);
		if (n == 0) break;
		val.clear();
		for (int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			val.push_back(a);
		}
		sort(val.begin(), val.end());
		DFS(0, 0);
		printf("\n");
	}
}