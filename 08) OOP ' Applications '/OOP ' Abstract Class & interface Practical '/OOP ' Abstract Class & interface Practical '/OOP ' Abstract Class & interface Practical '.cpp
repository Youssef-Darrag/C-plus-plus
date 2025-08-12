#include <iostream>
#include "clsPerson.h"
using namespace std;

int main()
{
    clsPerson Person("Youssef", "Abu-Darrag", "Goo@gmail.com", "4644626");

    cout << Person.FullName() << endl;



}