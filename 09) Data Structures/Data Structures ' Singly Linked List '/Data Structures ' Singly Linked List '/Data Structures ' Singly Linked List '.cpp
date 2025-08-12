#include <iostream>
using namespace std;

// " Singly Linked List Implementation "
class Node
{
public:
    int Value;
    Node* Next;
};

int main()
{
    Node* Head;

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
    Node2->Next = Node3;
    Node3->Next = NULL;

    Head = Node1;
    while (Head != NULL)
    {
        cout << Head->Value << endl;
        Head = Head->Next;
    }

    system("pause>0");

    return 0;
}










// " Operations - Insert At Beginning "
class Node
{
public:
    int Value;
    Node* Next;
};

void InsertAtBeginning(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = Head;

    Head = New_Node;
}

void PrintList(Node* Head)
{
    while (Head != NULL)
    {
        cout << Head->Value << " ";
        Head = Head->Next;
    }
}

int main()
{
    Node* Head = NULL;

    InsertAtBeginning(Head, 10);
    InsertAtBeginning(Head, 20);
    InsertAtBeginning(Head, 30);
    InsertAtBeginning(Head, 40);
    InsertAtBeginning(Head, 50);

    PrintList(Head);

    system("pause>0");

    return 0;
}










// " Operations - Find "
class Node
{
public:
    int Value;
    Node* Next;
};

void InsertAtBeginning(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = Head;

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
    while (Head != NULL)
    {
        cout << Head->Value << " ";
        Head = Head->Next;
    }
}

int main()
{
    Node* Head = NULL;

    InsertAtBeginning(Head, 10);
    InsertAtBeginning(Head, 20);
    InsertAtBeginning(Head, 30);
    InsertAtBeginning(Head, 40);
    InsertAtBeginning(Head, 50);

    PrintList(Head);

    Node* N1 = Find(Head, 30);

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
    int Value;
    Node* Next;
};

void InsertAtBeginning(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = Head;

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
        cout << "the given N1 can be NULL.";
        return;
    }

    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = N1->Next;

    N1->Next = New_Node;
}

void PrintList(Node* Head)
{
    cout << "\n";
    while (Head != NULL)
    {
        cout << Head->Value << " ";
        Head = Head->Next;
    }
}

int main()
{
    Node* Head = NULL;

    InsertAtBeginning(Head, 10);
    InsertAtBeginning(Head, 20);
    InsertAtBeginning(Head, 30);
    InsertAtBeginning(Head, 40);
    InsertAtBeginning(Head, 50);

    PrintList(Head);

    Node* N1 = NULL;
    N1 = Find(Head, 30);

    InsertAfter(N1, 500);

    PrintList(Head);

    system("pause>0");

    return 0;
}










// " Operations - Insert At End "
class Node
{
public:
    int Value;
    Node* Next;
};

void InsertAtBeginning(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = Head;

    Head = New_Node;
}

void InsertAtEnd(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = NULL;

    if (Head == NULL)
    {
        Head = New_Node;
        return;
    }

    Node* LastNode = Head;
    while (LastNode->Next != NULL)
    {
        LastNode = LastNode->Next;
    }

    LastNode->Next = New_Node;
    return;
}

void PrintList(Node* Head)
{
    cout << "\n";
    while (Head != NULL)
    {
        cout << Head->Value << " ";
        Head = Head->Next;
    }
}

int main()
{
    Node* Head = NULL;

    InsertAtEnd(Head, 20);
    InsertAtEnd(Head, 30);
    InsertAtEnd(Head, 40);
    InsertAtBeginning(Head, 10);

    PrintList(Head);

    system("pause>0");

    return 0;
}










// " Operations - Delete Node "
class Node
{
public:
    int Value;
    Node* Next;
};

void InsertAtEnd(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = NULL;

    if (Head == NULL)
    {
        Head = New_Node;
        return;
    }

    Node* LastNode = Head;
    while (LastNode->Next != NULL)
    {
        LastNode = LastNode->Next;
    }

    LastNode->Next = New_Node;
    return;
}

void DeleteNode(Node*& Head, int Value)
{
    Node* Current = Head, * Prev = Head;

    if (Head == NULL)
        return;

    if (Current->Value == Value)
    {
        Head = Current->Next;
        delete Current;
        return;
    }

    while (Current != NULL && Current->Value != Value)
    {
        Prev = Current;
        Current = Current->Next;
    }

    if (Current == NULL)
        return;

    Prev->Next = Current->Next;
    delete Current;
}

void PrintList(Node* Head)
{
    cout << "\n";
    while (Head != NULL)
    {
        cout << Head->Value << " ";
        Head = Head->Next;
    }
}

int main()
{
    Node* Head = NULL;

    InsertAtEnd(Head, 1);
    InsertAtEnd(Head, 2);
    InsertAtEnd(Head, 3);
    InsertAtEnd(Head, 4);
    InsertAtEnd(Head, 5);
    InsertAtEnd(Head, 6);

    PrintList(Head);

    DeleteNode(Head, 4);

    PrintList(Head);

    system("pause>0");

    return 0;
}










// " Operations - Delete First Node "
class Node
{
public:
    int Value;
    Node* Next;
};

void InsertAtEnd(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = NULL;

    if (Head == NULL)
    {
        Head = New_Node;
        return;
    }

    Node* LastNode = Head;
    while (LastNode->Next != NULL)
    {
        LastNode = LastNode->Next;
    }

    LastNode->Next = New_Node;
    return;
}

void DeleteFirstNode(Node*& Head)
{
    Node* FirstNode = Head;

    if (Head == NULL) 
        return;

    Head = FirstNode->Next;
    delete FirstNode;
    return;
}

void PrintList(Node* Head)
{
    cout << "\n";
    while (Head != NULL)
    {
        cout << Head->Value << " ";
        Head = Head->Next;
    }
}

int main()
{
    Node* Head = NULL;

    InsertAtEnd(Head, 1);
    InsertAtEnd(Head, 2);
    InsertAtEnd(Head, 3);
    InsertAtEnd(Head, 4);
    InsertAtEnd(Head, 5);
    InsertAtEnd(Head, 6);

    PrintList(Head);

    DeleteFirstNode(Head);

    PrintList(Head);

    system("pause>0");

    return 0;
}










// " Operations - Delete Last Node "
class Node
{
public:
    int Value;
    Node* Next;
};

void InsertAtEnd(Node*& Head, int Value)
{
    Node* New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Next = NULL;

    if (Head == NULL)
    {
        Head = New_Node;
        return;
    }

    Node* LastNode = Head;
    while (LastNode->Next != NULL)
    {
        LastNode = LastNode->Next;
    }

    LastNode->Next = New_Node;
    return;
}

void DeleteLastNode(Node*& Head)
{
    Node* Current = Head, * Prev = Head;

    if (Head == NULL)
        return;

    if (Current->Next == NULL)
    {
        Head = NULL;
        delete Current;
        return;
    }

    while (Current->Next != NULL)
    {
        Prev = Current;
        Current = Current->Next;
    }

    Prev->Next = NULL;
    delete Current;
}

void PrintList(Node* Head)
{
    cout << "\n";
    while (Head != NULL)
    {
        cout << Head->Value << " ";
        Head = Head->Next;
    }
}

int main()
{
    Node* Head = NULL;

    InsertAtEnd(Head, 1);
    InsertAtEnd(Head, 2);
    InsertAtEnd(Head, 3);
    InsertAtEnd(Head, 4);
    InsertAtEnd(Head, 5);
    InsertAtEnd(Head, 6);

    PrintList(Head);

    DeleteLastNode(Head);

    PrintList(Head);

    system("pause>0");

    return 0;
}