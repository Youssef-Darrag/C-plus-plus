#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> Num{ 1,2,3,4,5 };

    try
    {
        cout << Num.at(5) << endl;
    }
    catch (...)
    {
        cout << "out of bound" << endl;
    }

    return 0;
}