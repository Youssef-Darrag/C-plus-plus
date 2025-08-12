#include <iostream>
using namespace std;

enum enStonePaperScissors { Stone = 1, Paper = 2, Scissors = 3 };

short ReadHowManyRounds()
{
    short HowManyRounds = 0;
    do
    {
        cout << "How Many Rounds 1 to 10 ?" << endl;
        cin >> HowManyRounds;

    } while (HowManyRounds < 1 || HowManyRounds > 10);

    return HowManyRounds;
}

short RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enStonePaperScissors StonePaperScissors()
{
    switch (RandomNumber(1, 3))
    {
    case 1:
        return enStonePaperScissors::Stone;
    case 2:
        return enStonePaperScissors::Paper;
    case 3:
        return enStonePaperScissors::Scissors;
    }
}

string GetComputerChoice(enStonePaperScissors StonePaperScissors)
{
    if (StonePaperScissors == enStonePaperScissors::Stone)
        return "Stone";
    else if (StonePaperScissors == enStonePaperScissors::Paper)
        return "Paper";
    else if (StonePaperScissors == enStonePaperScissors::Scissors)
        return "Scissors";
}

short ReadPlayerChoice()
{
    short InputUser = 0;
    
    do
    {
        cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
        cin >> InputUser;

    } while (InputUser < 1 || InputUser > 3);

    return InputUser;
}

string ChoiceThePlayer(short Number)
{
    if (Number == 1)
        return "Stone";
    else if (Number == 2)
        return "Paper";
    else if (Number == 3)
        return "Scissors";
}

string RoundWinner(string Player, string Computer)
{
    if (Player == Computer)
    {
        system("color 6F");
        return "No Winner";
    }
    else if (Player == "Stone")
    {
        if (Computer == "Paper")
        {
            system("color 4F");
            return "Computer";
        }
        else if (Computer == "Scissors")
        {
            system("color 2F");
            return "Player";
        }
    }
    else if (Player == "Scissors")
    {
        if (Computer == "Stone")
        {
            system("color 4F");
            return "Computer";
        }
        else if (Computer == "Paper")
        {
            system("color 2F");
            return "Player";
        }
    }
    else if (Player == "Paper")
    {
        if (Computer == "Scissors")
        {
            system("color 4F");
            return "Computer";
        }
        else if (Computer == "Stone")
        {
            system("color 2F");
            return "Player";
        }
    }

}

void WinningTimes(string PlayerChoice, string ComputerChoice, short& PlayerWin, short& ComputerWin, short& NoWinnerWin)
{
    if (RoundWinner(PlayerChoice, ComputerChoice) == "Player")
        PlayerWin++;
    else if (RoundWinner(PlayerChoice, ComputerChoice) == "Computer")
        ComputerWin++;
    else if (RoundWinner(PlayerChoice, ComputerChoice) == "No Winner")
        NoWinnerWin++;
}

void ShowGameOverScreen()
{
    cout << "\t\t________________________________________________________________________\n\n";
    cout << "\t\t                         +++ G a m e O v e r +++                        \n\n";
    cout << "\t\t________________________________________________________________________\n\n";
}

string FinalWinner(short PlayerWin, short ComputerWin, short NoWinnerWin)
{
    if (PlayerWin > ComputerWin)
        return "Player";
    else if (ComputerWin > PlayerWin)
        return "Computer";
    else
        return "No Winner";
}

void ShowFinalGameResults(short HowManyRounds, short PlayerWin, short ComputerWin, short NoWinnerWin)
{
    cout << "\t\t___________________________ [ Game Results ] ___________________________\n\n";
    cout << "\t\tGame Rounds        :  " << HowManyRounds << endl;
    cout << "\t\tPlayer won times   :  " << PlayerWin << endl;
    cout << "\t\tComputer won times :  " << ComputerWin << endl;
    cout << "\t\tDraw times         :  " << NoWinnerWin << endl;
    cout << "\t\tFinal Winner       :  " << FinalWinner(PlayerWin, ComputerWin, NoWinnerWin) << endl << endl;
    cout << "\t\t________________________________________________________________________\n\n";
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void ForLoopForReadInfo(short HowManyRounds, short& PlayerWin, short& ComputerWin, short& NoWinnerWin)
{
    short InputUser;

    for (int i = 1; i <= HowManyRounds; i++)
    {

        cout << "\nRound [" << i << "] begins:" << endl << endl;
        InputUser = ReadPlayerChoice();
        string PlayerChoice = ChoiceThePlayer(InputUser);
        string ComputerChoice = GetComputerChoice(StonePaperScissors());
        string RoundWin = RoundWinner(PlayerChoice, ComputerChoice);

        cout << "\n__________________Round [" << i << "] ___________________" << endl;
        cout << "\n Player Choice  : " << PlayerChoice << endl;
        cout << " Computer Choice: " << ComputerChoice << endl;
        cout << " Round Winner   : [" << RoundWin << "]" << endl;
        WinningTimes(PlayerChoice, ComputerChoice, PlayerWin, ComputerWin, NoWinnerWin);

        cout << "\n_______________________________________________\n\n";
    }
}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResetScreen();

        short PlayerWin = 0, ComputerWin = 0, NoWinnerWin = 0;

        short HowManyRounds = ReadHowManyRounds();
        ForLoopForReadInfo(HowManyRounds, PlayerWin, ComputerWin, NoWinnerWin);

        ShowGameOverScreen();
        ShowFinalGameResults(HowManyRounds, PlayerWin, ComputerWin, NoWinnerWin);

        cout << "\t\tDo you want to play again? Y/N? ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}
    
int main()
{
    srand((unsigned)time(NULL));
    StartGame();

    return 0;
}