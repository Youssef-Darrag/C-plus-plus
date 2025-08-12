#include <iostream>
#include <fstream>
using namespace std;

// Lesson #52 " Write Mode : Write Data To File "
int main()
{
    fstream MyFile;

    MyFile.open("MyFile.txt", ios::out); // Write Mode
     
    if (MyFile.is_open())
    {
        MyFile << "Youssef\n";
        MyFile << "Fawzy\n";
        MyFile << "Darrag\n";

        MyFile.close();
    }

    return 0;
}







// Lesson #53 " Append Mode : Append Data To File "
int main()
{
    fstream MyFile;

    MyFile.open("MyFile.txt", ios::out | ios::app); // Append Mode

    if (MyFile.is_open())
    {
        MyFile << "Hi, this is a new line\n";
        MyFile << "Hi, this is another new line\n";

        MyFile.close();
    }

    return 0;
}





// Lesson #54 " Read Mode : Print File Content "
#include <string>
void PrintFileContent(string FileName)
{
	fstream MyFile;

	MyFile.open(FileName, ios::in); // Read Mode

	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line))  // focus on #include <string> for getline()
		{
			cout << Line << endl;
		}

		MyFile.close();
	}
}

int main()
{
	PrintFileContent("MyFile.txt");

	return 0;
}