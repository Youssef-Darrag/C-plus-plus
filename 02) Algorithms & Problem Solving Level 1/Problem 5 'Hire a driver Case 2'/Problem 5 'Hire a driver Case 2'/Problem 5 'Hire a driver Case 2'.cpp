#include <iostream>
using namespace std;

struct stInfo
{
    int Age;
    bool HasDrivingLicense;
    bool HasRecommendation;
};

stInfo ReadInfo()
{
    stInfo Info;

    cout << "Please,enter Your Age?" << endl;
    cin >> Info.Age;
    cout << "Do you have driver license?" << endl;
    cin >> Info.HasDrivingLicense;
    cout << "Do you have recommendation?" << endl;
    cin >> Info.HasRecommendation;

    return Info;
}

bool IsAccepted(stInfo Info)
{   
    if (Info.HasRecommendation)
    {
        return true;
    }
    else
    {
        return (Info.Age > 21 && Info.HasDrivingLicense);
    }
}

void PrintResult(stInfo Info)
{
    if (IsAccepted(Info))
        cout << "\n Hired" << endl;
    else
        cout << "\n Rejected" << endl;
}

int main()
{
    PrintResult(ReadInfo());

    return 0;
}