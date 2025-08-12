#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Lesson #55 " Load Data From File To Vector "
void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent)
{
    fstream MyFile;

    MyFile.open(FileName, ios::in); // Read Mode

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

int main()
{
    vector <string> vFileContent;

    LoadDataFromFileToVector("MyFile.txt", vFileContent);

    for (string& Line : vFileContent)
    {
        cout << Line << endl;
    }

    return 0;
}







// Lesson #56 " Save Vector To File "
void SaveVectorToFile(string FileName, vector<string> vFileContent)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out); // Write Mode

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

int main()
{
    vector <string> vFileContent{ "Ali","Shadi","Maher","Fadi","Lama" };

    SaveVectorToFile("MyFile.txt", vFileContent);

    return 0;
}