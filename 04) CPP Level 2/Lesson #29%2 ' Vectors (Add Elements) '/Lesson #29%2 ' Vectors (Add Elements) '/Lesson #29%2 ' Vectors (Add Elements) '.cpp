#include <iostream>
#include <vector>
using namespace std;

// Lesson Add Elements
int main()
{
    vector <int> vNumbers;

    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);
    vNumbers.push_back(50);
    vNumbers.push_back(60);
    vNumbers.push_back(70);
    vNumbers.push_back(80);
    vNumbers.push_back(90);

    cout << "Numbers Vector : \n\n";

    for (int& Number : vNumbers)
    {
        cout << Number << endl;
    }
    cout << endl;

    return 0;
}





// Homework
void ReadNumbers(vector <int>& vNumbers)
{
	int Number;
	char ReadMore = 'Y';

	do
	{
		cout << "Please,enter a number ? ";
		cin >> Number;

		vNumbers.push_back(Number);

		cout << "\nDo you want to read more numbers ? Y/N ? ";
		cin >> ReadMore;
	} while (ReadMore == 'Y' || ReadMore == 'y');
	cout << endl << endl;
}

void PrintVectorNumbers(vector <int>& vNumbers)
{
	cout << "Numbers Vector : \n\n";
	for (int& Number : vNumbers)
	{
		cout << Number << endl;
	}
	cout << endl;
}

int main()
{
	vector <int> vNumbers;

	ReadNumbers(vNumbers);
	PrintVectorNumbers(vNumbers);

	return 0;
}