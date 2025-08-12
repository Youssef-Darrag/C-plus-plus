#include <iostream>
#include <cstdio>

int main()
{
    char Name[] = "Youssef Abu_Darrag";
    char SchoolName[] = "Programming Advices";

    // Print string
    printf("Dear %s, How are you? \n\n", Name);
    printf("Welcome to %s School! \n\n", SchoolName);

    char c = 'S';

    // Print char
    printf("Setting the width of c :%*c \n", 1, c);
    printf("Setting the width of c :%*c \n", 2, c);
    printf("Setting the width of c :%*c \n", 3, c);
    printf("Setting the width of c :%*c \n", 4, c);
    printf("Setting the width of c :%*c \n", 5, c);

    return 0;
}