#include <iostream>
#include <vector>
#include "clsString.h"
using namespace std;

int main()
{
    clsString String1;
    clsString String2("Mohammed");

    String1.Value = "Ali Ahmed";

    cout << "String 1 = " << String1.Value << endl;
    cout << "String 2 = " << String2.Value << endl;

    cout << "Number of Words: " << String1.CountWords() << endl;
    cout << "Number of Words: " << String1.CountWords("Fadi ahmed rateb omer") << endl;
    cout << "Number of Words: " << clsString::CountWords("Mohammed Saqer Abu-Hadhoud") << endl;

    //-----------------

    clsString String3("hi how are you?");

    cout << "String 3 = " << String3.Value << endl;
    cout << "String Length = " << String3.Length() << endl;

    String3.UpperFirstLetterOfEachWord();
    cout << String3.Value << endl;
    
    //-----------------

    String3.LowerFirstLetterOfEachWord();
    cout << String3.Value << endl;

    //-----------------

    String3.UpperAllString();
    cout << String3.Value << endl;

    //-----------------

    String3.LowerAllString();
    cout << String3.Value << endl;

    //-----------------

    cout << "After inverting a: " << clsString::InvertLetterCase('a') << endl;

    //-----------------

    String3.Value = "AbCdEfg";

    String3.InvertAllLettersCase();

    cout << String3.Value << endl;

    String3.InvertAllLettersCase();

    cout << String3.Value << endl;

    //-----------------

    cout << "Capital Letters Count: " << clsString::CountLetters("Mohammed Abu-Hadhoud", clsString::CapitalLetters) << endl << endl;

    //-----------------

    String3.Value = "Welcome to Jordan";

    cout << String3.Value << endl;
    cout << "Capital Letters Count: " << String3.CountCapitalLetters() << endl;
    
    //-----------------

    cout << "Small Letters Count: " << String3.CountSmallLetters() << endl;

    //-----------------

    cout << "Vowels Count: " << String3.CountVowels() << endl;

    //-----------------

    cout << "Letter E Count: " << String3.CountSpecificLetter('E', true) << endl;
    cout << "Letter E Count: " << String3.CountSpecificLetter('E', false) << endl;

    //-----------------

    cout << "Is Letter u Vowel? " << clsString::IsVowel('u') << endl;

    //-----------------

    cout << "Words Count: " << String3.CountWords() << endl;

    //-----------------

    vector<string> vString;

    vString = String3.Split(" ");

    cout << "\nTokens = " << vString.size() << endl;

    for (string& S : vString)
    {
        cout << S << endl;
    }

    //-----------------
    // Trim

    String3.Value = "     Mohammed Abu-Hadhoud     ";
    cout << "\nString = " << String3.Value << endl;
    
    String3.Value = "     Mohammed Abu-Hadhoud     ";

    String3.TrimLeft();
    cout << "\nTrim Left = " << String3.Value << endl;

    //-----------------

    String3.Value = "     Mohammed Abu-Hadhoud     ";

    String3.TrimRight();
    cout << "\nTrim Right = " << String3.Value << endl;

    //-----------------

    String3.Value = "     Mohammed Abu-Hadhoud     ";

    String3.Trim();
    cout << "\nTrim = " << String3.Value << endl;

    //-----------------
    // Joins

    vector<string> vString1 = { "Mohammed", "Fadi", "Ali" , "Maher" };

    cout << "\nJoin String From Vector: \n";
    cout << clsString::JoinString(vString1, " ") << endl;

    string arrString[] = { "Mohammed", "Fadi", "Ali" , "Maher" };

    cout << "\nJoin String From array: \n";
    cout << clsString::JoinString(arrString, 4, " ") << endl;

    //-----------------

    String3.Value = "Mohammed Saqer Abu-Hadhoud";
    cout << "\nString = " << String3.Value << endl;

    String3.ReverseWordsInString();
    cout << "\nReverse Words: " << String3.Value << endl;

    //-----------------

    String3.Value = "Mohammed Saqer Abu-Hadhoud";

    cout << "\nReplace: " << String3.ReplaceWord("Mohammed", "Sari") << endl;

    //-----------------

    String3.Value = "This is: a sample text, with punctuations.";
    cout << "\nString = " << String3.Value << endl;

    String3.RemovePunctuations();
    cout << "\nRemove Punctuations: " << String3.Value << endl;

    system("pause>0");

    return 0;
}