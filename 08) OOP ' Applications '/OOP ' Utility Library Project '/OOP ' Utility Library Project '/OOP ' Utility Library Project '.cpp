#include <iostream>
#include "clsUtil.h"
using namespace std;

int main()
{
    clsUtil::Srand();

    cout << clsUtil::RandomNumber(1, 10) << endl;

    cout << clsUtil::GetRandomCharacter(clsUtil::CapitalLetter) << endl;

    cout << clsUtil::GenerateWord(clsUtil::MixChars, 8) << endl;

    cout << clsUtil::GenerateKey(clsUtil::MixChars) << endl;

    clsUtil::GenerateKeys(10, clsUtil::MixChars);

    cout << "\n";

    // Swap int

    int x = 10, y = 20;

    cout << x << " " << y << endl;

    clsUtil::Swap(x, y);

    cout << x << " " << y << endl << endl;

    // Swap double

    double a = 10.5, b = 20.5;

    cout << a << " " << b << endl;

    clsUtil::Swap(a, b);

    cout << a << " " << b << endl << endl;

    // Swap string

    string s1 = "Ali", s2 = "Ahmed";

    cout << s1 << " " << s2 << endl;

    clsUtil::Swap(s1, s2);

    cout << s1 << " " << s2 << endl << endl;

    // Swap Dates

    clsDate d1(1, 10, 2022), d2(1, 1, 2022);

    cout << d1.DateToString() << " " << d2.DateToString() << endl;

    clsUtil::Swap(d1, d2);

    cout << d1.DateToString() << " " << d2.DateToString() << endl << endl;

    // Shuffle Array
    // int Array

    int Arr1[5] = { 1,2,3,4,5 };

    clsUtil::ShuffleArray(Arr1, 5);

    cout << "\nArray after shuffle:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr1[i] << endl;
    }

    // string Array

    string Arr2[5] = { "Ali", "Fadi", "Ahmed", "Qasem", "Khalid" };

    clsUtil::ShuffleArray(Arr2, 5);

    cout << "\nArray after shuffle:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr2[i] << endl;
    }

    // Fill Array
    // int Array

    int Arr3[5];

    clsUtil::FillArrayWithRandomNumbers(Arr3, 5, 20, 50);

    cout << "\nArray after Fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr3[i] << endl;
    }

    // string Array
    // Words

    string Arr4[5];

    clsUtil::FillArrayWithRandomWords(Arr4, 5, clsUtil::MixChars, 8);

    cout << "\nArray after Fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr4[i] << endl;
    }

    // Keys

    string Arr5[5];

    clsUtil::FillArrayWithRandomKeys(Arr5, 5, clsUtil::MixChars);

    cout << "\nArray after Filling Keys:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr5[i] << endl;
    }

    cout << "\nText1 " << clsUtil::Tabs(5) << "Text2\n";

    const short EncryptionKey = 2;

    string TextAfterEncryption, TextAfterDecryption;

    string Text = "Youssef Abu-Darrag";

    TextAfterEncryption = clsUtil::EncryptText(Text, EncryptionKey);
    TextAfterDecryption = clsUtil::DecryptText(TextAfterEncryption, EncryptionKey);

    cout << "\nText Before Encryption: ";
    cout << Text << endl;

    cout << "\nText After Encryption: ";
    cout << TextAfterEncryption << endl;

    cout << "\nText After Decryption: ";
    cout << TextAfterDecryption << endl;

    system("pause>0");

    return 0;
}