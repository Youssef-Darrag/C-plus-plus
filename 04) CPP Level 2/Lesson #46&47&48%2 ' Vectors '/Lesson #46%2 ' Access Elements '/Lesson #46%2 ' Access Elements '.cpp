#include <iostream>
#include <vector>
using namespace std;

// Lesson #46 " Vector ( Access Elements ) "
int main()
{
    vector <int> Num{ 1,2,3,4,5 };

    cout << " Using .at(i) \n";
    cout << "Element at Index 0: " << Num.at(0) << endl;
    cout << "Element at Index 2: " << Num.at(2) << endl;
    cout << "Element at Index 4: " << Num.at(4) << endl;

    cout << "\n\n Using [i] \n";
    cout << "Element at Index 0: " << Num[0] << endl;
    cout << "Element at Index 2: " << Num[2] << endl;
    cout << "Element at Index 4: " << Num[4] << endl;

    return 0;
}






// Lesson #47 " Vector ( Change Elements ) "
int main()
{
    vector <int> Num{ 1,2,3,4,5 };

    cout << " Initial Vector: ";
    for (const int& i : Num)
    {
        cout << i << " ";
    }

    cout << "\n\n Updated Vector: ";
    for (int& i : Num)
    {
        i = 20;
        cout << i << " ";
    }

    Num[1] = 40;
    Num.at(2) = 80;
    Num.at(4) = 90;

    cout << "\n\n Updated Vector: ";
    for (const int& i : Num)
    {
        cout << i << " ";
    }

    return 0;
}






// Lesson #48 " Vector ( Iterators ) "
int main()
{
    vector <int> Num{ 1,2,3,4,5 };

    // declare iterator
    vector <int>::iterator iter;

    // use iterator with for loop
    for (iter = Num.begin(); iter != Num.end(); iter++)
    {
        cout << *iter << " ";
    }

    return 0;  
}