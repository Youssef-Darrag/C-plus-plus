#include <iostream>
using namespace std;

// " Doubly Linked List Implementation "
class Node
{
public:
    Node* Prev;
    int Value;
    Node* Next;
};

int main()
{
    Node* Head = NULL;
    
    Node* Node1 = NULL;
    Node* Node2 = NULL;
    Node* Node3 = NULL;

    Node1 = new Node();
    Node2 = new Node();
    Node3 = new Node();

    Node1->Value = 10;
    Node2->Value = 20;
    Node3->Value = 30;

    Node1->Next = Node2;
    Node1->Prev = NULL;

    Node2->Next = Node3;
    Node2->Prev = Node1;

    Node3->Next = NULL;
    Node3->Prev = Node2;

    Head = Node1;
    while (Head != NULL)
    {
        cout << Head->Value << endl;
        Head = Head->Next;
    }

    cout << "\n";

    Head = Node3;
    while (Head != NULL)
    {
        cout << Head->Value << endl;
        Head = Head->Prev;
    }

    system("pause>0");

    return 0;
}










// " Operations - Insert At Beginning "
class Node
{
public:
    Node* Prev;
    int Value;
    Node* Next;
};

void InsertAtBeginning(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = Head;
    New_Node->Prev = NULL;

    if (Head != NULL)
    {
        Head->Prev = New_Node;
    }

    Head = New_Node;
}

void PrintNodeDetails(Node* Head)
{
    if (Head->Prev != NULL)
        cout << Head->Prev->Value;
    else
        cout << "NULL";

    cout << " <--> " << Head->Value << " <--> ";

    if (Head->Next != NULL)
        cout << Head->Next->Value << "\n";
    else
        cout << "NULL";
}

void PrintListDetails(Node* Head)
{
    cout << "\n";
    while (Head != NULL)
    {
        PrintNodeDetails(Head);
        Head = Head->Next;
    }
}

void PrintList(Node* Head)
{
    cout << "NULL <--> ";
    while (Head != NULL)
    {
        cout << Head->Value << " <--> ";
        Head = Head->Next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node* Head = NULL;

    InsertAtBeginning(Head, 5);
    InsertAtBeginning(Head, 4);
    InsertAtBeginning(Head, 3);
    InsertAtBeginning(Head, 2);
    InsertAtBeginning(Head, 1);

    cout << "\nLinked List Content:\n";
    PrintList(Head);

    PrintListDetails(Head);

    system("pause>0");

    return 0;
}










// " Operations - Find "
class Node
{
public:
    Node* Prev;
    int Value;
    Node* Next;
};

void InsertAtBeginning(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = Head;
    New_Node->Prev = NULL;

    if (Head != NULL)
    {
        Head->Prev = New_Node;
    }

    Head = New_Node;
}

Node* Find(Node* Head, int Value)
{
    while (Head != NULL)
    {
        if (Head->Value == Value)
            return Head;

        Head = Head->Next;
    }

    return NULL;
}

void PrintList(Node* Head)
{
    cout << "NULL <--> ";
    while (Head != NULL)
    {
        cout << Head->Value << " <--> ";
        Head = Head->Next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node* Head = NULL;

    InsertAtBeginning(Head, 5);
    InsertAtBeginning(Head, 4);
    InsertAtBeginning(Head, 3);
    InsertAtBeginning(Head, 2);
    InsertAtBeginning(Head, 1);

    cout << "\nLinked List Content:\n";
    PrintList(Head);

    Node* N1 = Find(Head, 4);

    if (N1 != NULL)
        cout << "\nNode Found :-)\n";
    else
        cout << "\nNode is not Found :-(\n";

    system("pause>0");

    return 0;
}










// " Operations - Insert After "
class Node
{
public:
    Node* Prev;
    int Value;
    Node* Next;
};

void InsertAtBeginning(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = Head;
    New_Node->Prev = NULL;

    if (Head != NULL)
    {
        Head->Prev = New_Node;
    }

    Head = New_Node;
}

Node* Find(Node* Head, int Value)
{
    while (Head != NULL)
    {
        if (Head->Value == Value)
            return Head;

        Head = Head->Next;
    }

    return NULL;
}

void InsertAfter(Node* N1, int Value)
{
    if (N1 == NULL)
    {
        cout << "\n\nthe given N1 can be NULL.";
        return;
    }

    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = N1->Next;
    New_Node->Prev = N1;

    if (N1->Next != NULL)
    {
        N1->Next->Prev = New_Node;
    }

    N1->Next = New_Node;
}

void PrintNodeDetails(Node* Head)
{
    if (Head->Prev != NULL)
        cout << Head->Prev->Value;
    else
        cout << "NULL";

    cout << " <--> " << Head->Value << " <--> ";

    if (Head->Next != NULL)
        cout << Head->Next->Value << "\n";
    else
        cout << "NULL";
}

void PrintListDetails(Node* Head)
{
    cout << "\n";
    while (Head != NULL)
    {
        PrintNodeDetails(Head);
        Head = Head->Next;
    }
}

void PrintList(Node* Head)
{
    cout << "NULL <--> ";
    while (Head != NULL)
    {
        cout << Head->Value << " <--> ";
        Head = Head->Next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node* Head = NULL;

    InsertAtBeginning(Head, 5);
    InsertAtBeginning(Head, 4);
    InsertAtBeginning(Head, 3);
    InsertAtBeginning(Head, 2);
    InsertAtBeginning(Head, 1);

    cout << "\nLinked List Content:\n";
    PrintList(Head);
    PrintListDetails(Head);

    Node* N1 = Find(Head, 2);

    InsertAfter(N1, 500);

    cout << "\n\n\nLinked List Content after Insert After:\n";
    PrintList(Head);
    PrintListDetails(Head);

    system("pause>0");

    return 0;
}










// " Operations - Insert At End "
class Node
{
public:
    Node* Prev;
    int Value;
    Node* Next;
};

void InsertAtBeginning(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = Head;
    New_Node->Prev = NULL;

    if (Head != NULL)
    {
        Head->Prev = New_Node;
    }

    Head = New_Node;
}

void InsertAtEnd(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = NULL;
    
    if (Head == NULL)
    {
        New_Node->Prev = NULL;
        Head = New_Node;
    }
    else
    {
        Node* LastNode = Head;
        while (LastNode->Next != NULL)
        {
            LastNode = LastNode->Next;
        }

        New_Node->Prev = LastNode;
        LastNode->Next = New_Node;
    }

}

void PrintNodeDetails(Node* Head)
{
    if (Head->Prev != NULL)
        cout << Head->Prev->Value;
    else
        cout << "NULL";

    cout << " <--> " << Head->Value << " <--> ";

    if (Head->Next != NULL)
        cout << Head->Next->Value << "\n";
    else
        cout << "NULL";
}

void PrintListDetails(Node* Head)
{
    cout << "\n";
    while (Head != NULL)
    {
        PrintNodeDetails(Head);
        Head = Head->Next;
    }
}

void PrintList(Node* Head)
{
    cout << "NULL <--> ";
    while (Head != NULL)
    {
        cout << Head->Value << " <--> ";
        Head = Head->Next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node* Head = NULL;

    InsertAtBeginning(Head, 5);
    InsertAtBeginning(Head, 4);
    InsertAtBeginning(Head, 3);
    InsertAtBeginning(Head, 2);
    InsertAtBeginning(Head, 1);

    cout << "\nLinked List Content:\n";
    PrintList(Head);
    PrintListDetails(Head);

    InsertAtEnd(Head, 500);

    cout << "\n\n\nLinked List Content after Insert At End:\n";
    PrintList(Head);
    PrintListDetails(Head);

    system("pause>0");

    return 0;
}










// " Operations - Delete Node "
class Node
{
public:
    Node* Prev;
    int Value;
    Node* Next;
};

void InsertAtBeginning(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = Head;
    New_Node->Prev = NULL;

    if (Head != NULL)
    {
        Head->Prev = New_Node;
    }

    Head = New_Node;
}

Node* Find(Node* Head, int Value)
{
    while (Head != NULL)
    {
        if (Head->Value == Value)
            return Head;

        Head = Head->Next;
    }

    return NULL;
}

void DeleteNode(Node*& Head, Node*& NodeToDelete)
{
    if (Head == NULL || NodeToDelete == NULL)
        return;

    if (Head == NodeToDelete)
        Head = NodeToDelete->Next;


    if (NodeToDelete->Next != NULL)
        NodeToDelete->Next->Prev = NodeToDelete->Prev;

    if (NodeToDelete->Prev != NULL)
        NodeToDelete->Prev->Next = NodeToDelete->Next;

    delete NodeToDelete;
}

void PrintNodeDetails(Node* Head)
{
    if (Head->Prev != NULL)
        cout << Head->Prev->Value;
    else
        cout << "NULL";

    cout << " <--> " << Head->Value << " <--> ";

    if (Head->Next != NULL)
        cout << Head->Next->Value << "\n";
    else
        cout << "NULL";
}

void PrintListDetails(Node* Head)
{
    cout << "\n";
    while (Head != NULL)
    {
        PrintNodeDetails(Head);
        Head = Head->Next;
    }
}

void PrintList(Node* Head)
{
    cout << "NULL <--> ";
    while (Head != NULL)
    {
        cout << Head->Value << " <--> ";
        Head = Head->Next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node* Head = NULL;

    InsertAtBeginning(Head, 5);
    InsertAtBeginning(Head, 4);
    InsertAtBeginning(Head, 3);
    InsertAtBeginning(Head, 2);
    InsertAtBeginning(Head, 1);

    cout << "\nLinked List Content:\n";
    PrintList(Head);
    PrintListDetails(Head);

    Node* N1 = Find(Head, 4);

    DeleteNode(Head, N1);

    cout << "\n\n\nLinked List Content after Delete:\n";
    PrintList(Head);
    PrintListDetails(Head);

    system("pause>0");

    return 0;
}










// " Operations - Delete First Node "
class Node
{
public:
    Node* Prev;
    int Value;
    Node* Next;
};

void InsertAtBeginning(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = Head;
    New_Node->Prev = NULL;

    if (Head != NULL)
    {
        Head->Prev = New_Node;
    }

    Head = New_Node;
}

void DeleteFirstNode(Node*& Head)
{
    if (Head == NULL)
        return;

    Node* FirstNode = Head;

    Head = FirstNode->Next;
    if (Head != NULL)
        Head->Prev = NULL;

    delete FirstNode;
}

void PrintNodeDetails(Node* Head)
{
    if (Head->Prev != NULL)
        cout << Head->Prev->Value;
    else
        cout << "NULL";

    cout << " <--> " << Head->Value << " <--> ";

    if (Head->Next != NULL)
        cout << Head->Next->Value << "\n";
    else
        cout << "NULL";
}

void PrintListDetails(Node* Head)
{
    cout << "\n";
    while (Head != NULL)
    {
        PrintNodeDetails(Head);
        Head = Head->Next;
    }
}

void PrintList(Node* Head)
{
    cout << "NULL <--> ";
    while (Head != NULL)
    {
        cout << Head->Value << " <--> ";
        Head = Head->Next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node* Head = NULL;

    InsertAtBeginning(Head, 5);
    InsertAtBeginning(Head, 4);
    InsertAtBeginning(Head, 3);
    InsertAtBeginning(Head, 2);
    InsertAtBeginning(Head, 1);

    cout << "\nLinked List Content:\n";
    PrintList(Head);
    PrintListDetails(Head);

    DeleteFirstNode(Head);

    cout << "\n\n\nLinked List Content after Delete First Node:\n";
    PrintList(Head);
    PrintListDetails(Head);

    system("pause>0");

    return 0;
}










// " Operations - Delete Last Node "
class Node
{
public:
    Node* Prev;
    int Value;
    Node* Next;
};

void InsertAtBeginning(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = Head;
    New_Node->Prev = NULL;

    if (Head != NULL)
    {
        Head->Prev = New_Node;
    }

    Head = New_Node;
}

void DeleteLastNode(Node*& Head)
{
    if (Head == NULL)
        return;

    if (Head->Next == NULL)
    {
        delete Head;
        Head == NULL;
        return;
    }

    Node* Current = Head;
    while (Current->Next->Next != NULL)
    {
        Current = Current->Next;
    }

    Node* Temp = Current->Next;
    Current->Next = NULL;
    delete Temp;
}

void PrintNodeDetails(Node* Head)
{
    if (Head->Prev != NULL)
        cout << Head->Prev->Value;
    else
        cout << "NULL";

    cout << " <--> " << Head->Value << " <--> ";

    if (Head->Next != NULL)
        cout << Head->Next->Value << "\n";
    else
        cout << "NULL";
}

void PrintListDetails(Node* Head)
{
    cout << "\n";
    while (Head != NULL)
    {
        PrintNodeDetails(Head);
        Head = Head->Next;
    }
}

void PrintList(Node* Head)
{
    cout << "NULL <--> ";
    while (Head != NULL)
    {
        cout << Head->Value << " <--> ";
        Head = Head->Next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node* Head = NULL;

    InsertAtBeginning(Head, 5);
    InsertAtBeginning(Head, 4);
    InsertAtBeginning(Head, 3);
    InsertAtBeginning(Head, 2);
    InsertAtBeginning(Head, 1);

    cout << "\nLinked List Content:\n";
    PrintList(Head);
    PrintListDetails(Head);

    DeleteLastNode(Head);

    cout << "\n\n\nLinked List Content after Delete Last Node:\n";
    PrintList(Head);
    PrintListDetails(Head);

    system("pause>0");

    return 0;
}