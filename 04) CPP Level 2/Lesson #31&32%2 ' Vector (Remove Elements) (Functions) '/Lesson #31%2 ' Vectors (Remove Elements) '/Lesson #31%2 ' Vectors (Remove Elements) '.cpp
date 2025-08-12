#include <iostream>
#include <vector>
using namespace std;

// Lesson #31 " Remove Elements "
int main()
{
    vector <int> vNumbers;

    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);
    vNumbers.push_back(50);

    vNumbers.pop_back();
    vNumbers.pop_back();
    vNumbers.pop_back();
    vNumbers.pop_back();
    vNumbers.pop_back();

    cout << "Numbers Vector : \n\n";

    for (int& Number : vNumbers)
    {
        cout << Number << endl;
    }
    cout << endl;

    return 0;
}





// Lesson #32 " Vector Functions "
int main()
{
    vector <int> vNumbers;

    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);
    vNumbers.push_back(50);

    cout << "First Element: " << vNumbers.front() << endl;
    cout << "Last Element: " << vNumbers.back() << endl;

    // returns the number of elements present in the vector
    cout << "Size: " << vNumbers.size() << endl;

    // check the overall size of a vector
    cout << "Capacity: " << vNumbers.capacity() << endl;

    // returns 1 (true) if the vector is empty
    cout << "Empty: " << vNumbers.empty() << endl;

    return 0;
}