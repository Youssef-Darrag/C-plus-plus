
#include <iostream>
using namespace std;

enum enColor { Red, Green, Yellow, Blue };
enum enGender { Male, Female };
enum enStatus { Single, Married };

struct stAddress
{
    string StreetName;
    string BuildNumber;
    string POBox;
    string ZipCode;
};

struct stContactInfo
{
    string Phone; 
    string Email;
    stAddress Address;
};

struct stPerson
{
    string FirstName;
    string LastName;
    stContactInfo ContactInfo;
    enColor FavColor;
    enGender Gender;
    enStatus Status;
};
int main()
{
    stPerson Person;
     
    Person.FirstName = " Youssef";
    Person.LastName = " Darrag";

    Person.ContactInfo.Email = " hgdhshdfgsd";
    Person.ContactInfo.Phone = " 01065464654";
    Person.ContactInfo.Address.POBox = " 7777";
    Person.ContactInfo.Address.ZipCode = " 3248566";
    Person.ContactInfo.Address.StreetName = " Abu_Darrag Street";
    Person.ContactInfo.Address.BuildNumber = " 140";

    Person.FavColor = enColor::Green;
    Person.Gender = enGender::Male;
    Person.Status = enStatus::Single;

    cout << Person.ContactInfo.Address.StreetName << endl;












    return 0;
}

