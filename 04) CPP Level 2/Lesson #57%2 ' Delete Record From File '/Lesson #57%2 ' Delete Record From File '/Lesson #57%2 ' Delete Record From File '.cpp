#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void LoadDataFromFileToVector(vector <string>& vFileContent)
{
    fstream MyFile;

    MyFile.open("MyFile.txt", ios::in); // Read Mode

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            vFileContent.push_back(Line);
        }

        MyFile.close();
    }
}

void SaveVectorToFile(vector <string> vFileContent)
{
    fstream MyFile;

    MyFile.open("MyFile.txt", ios::out); // Write Mode

    if (MyFile.is_open())
    {
        for (string& Line : vFileContent)
        {
            if (Line != "")
            {
                MyFile << Line << endl;
            }
        }

        MyFile.close();
    }
}

void DeleteRecordFromFile(string Record)
{
    vector <string> vFileContent;

    LoadDataFromFileToVector(vFileContent);

    for (string& Line : vFileContent)
    {
        if (Line == Record)
        {
            Line = "";
        }
    }

    SaveVectorToFile(vFileContent);
}

void PrintFileContent()
{
    fstream MyFile;

    MyFile.open("MyFile.txt", ios::in); // Read Mode

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            cout << Line << endl;
        }

        MyFile.close();
    }
}

int main()
{
    cout << "File Content Before Delete. \n";
    PrintFileContent();

    DeleteRecordFromFile("Ali");

    cout << "\n\nFile Content After Delete. \n";
    PrintFileContent();

    return 0;
}