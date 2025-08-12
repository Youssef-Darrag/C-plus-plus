#include <iostream>
#include "clsInputValidate.h"
using namespace std;

int main()
{
    cout << clsInputValidate::IsNumberBetween<int>(5, 1, 10) << endl;
    cout << clsInputValidate::IsNumberBetween<float>(5.5, 1.3, 10.8) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(),clsDate(3,7,2024),clsDate(15,7,2024)) << endl;
    cout << clsInputValidate::IsDateBetween(clsDate(),clsDate(15,7,2024),clsDate(3,7,2024)) << endl;

    cout << "\nPlease Enter a Number:\n";
    int x = clsInputValidate::ReadNumber<int>("Invalid Number, Enter again:\n");
    cout << "x = " << x << "\n";

    cout << "\nPlease Enter a Number between 1 and 5:\n";
    int y = clsInputValidate::ReadNumberBetween<int>(1, 5, "Number is not within range, enter again\n");
    cout << "y = " << y << "\n";

    cout << "\nPlease Enter a Double Number:\n";
    double a = clsInputValidate::ReadNumber<double>("Invalid Number, Enter again:\n");
    cout << "a = " << a << "\n";

    cout << "\nPlease Enter a Double Number between 1 and 5:\n";
    double b = clsInputValidate::ReadNumberBetween<double>(1, 5, "Number is not within range, enter again\n");
    cout << "b = " << b << "\n";

    cout << clsInputValidate::IsValideDate(clsDate(35, 12, 2024)) << endl;

    system("pause>0");

    return 0;
}