#include <iostream>
using namespace std;

int main()
{
	int Today;
	cout << "Please,enter this today?\n";
	cin >> Today;
	if (Today == 1)
	{
		cout << "Its Sunday\n";
	}
	else if (Today == 2)
	{
		cout << "Its Monday\n";
	}
	else if (Today == 3)
	{
		cout << "Its Tuesday\n";
	}
	else if (Today == 4)
	{
		cout << "Its Wednesday\n";
	}
	else if (Today == 5)
	{
		cout << "Its Thursday\n";
	}
	else if (Today == 6)
	{
		cout << "Its Friday\n";
	}
	else if (Today == 7)
	{
		cout << "Its Saturday\n";
	}
	else
	{
		cout << "Wrong Day\n";
	};
	return 0;
}
