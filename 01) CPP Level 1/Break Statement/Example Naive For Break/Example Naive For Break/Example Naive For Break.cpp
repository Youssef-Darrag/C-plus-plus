#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 10; i++)
    {   // condition to break

        if (i == 3)
        {
            break;
        }

        cout << i << endl;
    }

    return 0;
}
