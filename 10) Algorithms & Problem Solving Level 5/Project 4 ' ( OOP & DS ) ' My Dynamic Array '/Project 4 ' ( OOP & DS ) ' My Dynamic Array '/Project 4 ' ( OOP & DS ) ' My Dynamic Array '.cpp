#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

int main()
{
    clsDynamicArray<int> MyDynamicArray(5);
    
    MyDynamicArray.SetItem(0, 10);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 50);

    cout << "\nIs Empty? " << MyDynamicArray.IsEmpty();
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    cout << "\nArray Items:\n";
    MyDynamicArray.PrintList();

    /*MyDynamicArray.Resize(2);
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    cout << "\nArray Items after resize to 2:\n";
    MyDynamicArray.PrintList();

    MyDynamicArray.Resize(10);
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    cout << "\nArray Items after resize to 10:\n";
    MyDynamicArray.PrintList();*/

    /*cout << "\nItem(2): " << MyDynamicArray.GetItem(2) << "\n";

    MyDynamicArray.Reverse();
    cout << "\nArray Items after Reverse():\n";
    MyDynamicArray.PrintList();

    MyDynamicArray.Clear();
    cout << "\nArray Items after Clear():\n";
    MyDynamicArray.PrintList();*/

    /*MyDynamicArray.DeleteItemAt(2);
    cout << "\nArray Items after deleting item(2):\n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    MyDynamicArray.PrintList();*/

    /*MyDynamicArray.DeleteFirstItem();
    cout << "\nArray Items after deleting FirstItem:\n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    MyDynamicArray.PrintList();

    MyDynamicArray.DeleteLastItem();
    cout << "\nArray Items after deleting LastItem:\n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    MyDynamicArray.PrintList();*/

    /*int Index = MyDynamicArray.Find(30);
    if (Index == -1)
        cout << "\nItem was not Found :-(\n";
    else
        cout << "\n30 is found at index: " << Index << "\n";

    MyDynamicArray.DeleteItem(30);
    cout << "\nArray Items after deleting 30:\n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    MyDynamicArray.PrintList();*/

    /*MyDynamicArray.InsertAt(2, 500);
    cout << "\nArray Items after insert 500 at index 2:\n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    MyDynamicArray.PrintList();*/

    /*MyDynamicArray.InsertAtBeginning(400);
    cout << "\n\nArray after insert 400 at Beginning:\n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    MyDynamicArray.PrintList();

    MyDynamicArray.InsertBefore(2, 500);
    cout << "\n\nArray after insert 500 before index 2:\n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    MyDynamicArray.PrintList();

    MyDynamicArray.InsertAfter(2, 600);
    cout << "\n\nArray after insert 600 after index 2:\n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    MyDynamicArray.PrintList();

    MyDynamicArray.InsertAtEnd(800);
    cout << "\n\nArray after insert 800 at End:\n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    MyDynamicArray.PrintList();*/

    system("pause>0");

    return 0;
}