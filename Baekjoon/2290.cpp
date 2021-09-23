#include <iostream>
#include <string>

using namespace std;

int s;
string nstr;

void printnumber(char n, int pos)
{
	bool ishorizon = pos == 0 || pos == s + 1 || pos == 2 * s + 2;
	switch (n)
	{
	case '1':
		if (ishorizon)
		{
			for (int i = 0; i < s + 2; i++)
				cout << " ";
		}
		else
		{
			for (int j = 0; j < s + 1; j++)
				cout << " ";
			cout << "|";
		}
		break;
	case '2':
		if (ishorizon)
		{
			cout << " ";
			for (int i = 1; i < s + 1; i++)
				cout << "-";
			cout << " ";
		}
		else if (pos < s + 1)
		{
			for (int j = 0; j < s + 1; j++)
				cout << " ";
			cout << "|";
		}
		else
		{
			cout << "|";
			for (int j = 0; j < s + 1; j++)
				cout << " ";
		}
		break;
	case '3':
		if (ishorizon)
		{
			cout << " ";
			for (int i = 1; i < s + 1; i++)
				cout << "-";
			cout << " ";
		}
		else
		{
			for (int j = 0; j < s + 1; j++)
				cout << " ";
			cout << "|";
		}
		break;
	case '4':
		if (ishorizon)
		{
			if (pos == s + 1)
			{
				cout << " ";
				for (int i = 1; i < s + 1; i++)
					cout << "-";
				cout << " ";
			}
			else
			{
				for (int i = 0; i < s + 2; i++)
					cout << " ";
			}
		}
		else if (pos < s + 1)
		{
			cout << "|";
			for (int j = 1; j < s + 1; j++)
				cout << " ";
			cout << "|";
		}
		else
		{
			for (int j = 0; j < s + 1; j++)
				cout << " ";
			cout << "|";
		}
		break;
	case '5':
		if (ishorizon)
		{
			cout << " ";
			for (int i = 1; i < s + 1; i++)
				cout << "-";
			cout << " ";
		}
		else if (pos < s + 1)
		{
			cout << "|";
			for (int j = 0; j < s + 1; j++)
				cout << " ";
		}
		else
		{
			for (int j = 0; j < s + 1; j++)
				cout << " ";
			cout << "|";
		}
		break;
	case '6':
		if (ishorizon)
		{
			cout << " ";
			for (int i = 1; i < s + 1; i++)
				cout << "-";
			cout << " ";
		}
		else if (pos < s + 1)
		{
			cout << "|";
			for (int j = 0; j < s + 1; j++)
				cout << " ";
		}
		else
		{
			cout << "|";
			for (int j = 1; j < s + 1; j++)
				cout << " ";
			cout << "|";
		}
		break;
	case '7':
		if (ishorizon)
		{
			if (pos == 0)
			{
				cout << " ";
				for (int i = 1; i < s + 1; i++)
					cout << "-";
				cout << " ";
			}
			else
			{
				for (int i = 0; i < s + 2; i++)
					cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < s + 1; j++)
				cout << " ";
			cout << "|";
		}
		break;
	case '8':
		if (ishorizon)
		{
			cout << " ";
			for (int i = 1; i < s + 1; i++)
				cout << "-";
			cout << " ";
		}
		else
		{
			cout << "|";
			for (int j = 1; j < s + 1; j++)
				cout << " ";
			cout << "|";
		}
		break;
	case '9':
		if (ishorizon)
		{
			cout << " ";
			for (int i = 1; i < s + 1; i++)
				cout << "-";
			cout << " ";
		}
		else if (pos < s + 1)
		{
			cout << "|";
			for (int j = 1; j < s + 1; j++)
				cout << " ";
			cout << "|";
		}
		else
		{
			for (int j = 0; j < s + 1; j++)
				cout << " ";
			cout << "|";
		}
		break;
	case '0':
		if (ishorizon)
		{
			if (pos == s + 1)
			{
				for (int i = 0; i < s + 2; i++)
					cout << " ";
			}
			else
			{
				cout << " ";
				for (int i = 1; i < s + 1; i++)
					cout << "-";
				cout << " ";
			}
		}
		else
		{
			cout << "|";
			for (int j = 1; j < s + 1; j++)
				cout << " ";
			cout << "|";
		}
		break;
	}
}

int main(void)
{
	int n;
	cin >> s >> n;
	nstr = to_string(n);

	for (int i = 0; i < 2 * s + 3; i++)
	{
		for (int j = 0; j < nstr.size(); j++)
		{
			printnumber(nstr[j], i);
			cout << " ";
		}
		cout << endl;
	}
}