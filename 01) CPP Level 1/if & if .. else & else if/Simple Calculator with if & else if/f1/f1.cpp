#include <iostream>
using namespace std;

int main()
{
	float N1, N2; char OperationType;

	cout << "Please,enter N1?\n";
	cin >> N1;
	cout << "Please,enter N2?\n";
	cin >> N2;
	cout << "Please,enter OperationType?\n";
	cin >> OperationType;
	
	if (OperationType == '+')
	{
		cout << "Add the two numbers = " << N1 + N2 << endl;
	}
	else if (OperationType == '-')
	{
		cout << "Subtract the two numbers = " << N1 - N2 << endl;
	}
	else if (OperationType == '*')
	{
		cout << "Multiply the two numbers = " << N1 * N2 << endl;
	}
	else if (OperationType == '/')
	{
		cout << "Devide the two numbers = " << N1 / N2 << endl;
	}
	return 0;
}
