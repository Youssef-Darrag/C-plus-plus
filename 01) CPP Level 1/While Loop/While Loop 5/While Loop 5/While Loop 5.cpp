#include <iostream>
using namespace std;

int main()
{
	int Number;
	cout << "Please,enter the Number?\n";
	cin >> Number;

	while (Number >= 1)
	{
		cout << Number << endl;
		Number--;
	}

	return 0;
}
