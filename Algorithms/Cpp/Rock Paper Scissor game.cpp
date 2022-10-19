#include <iostream>
#include <cstdlib> 
#include <ctime>   

// Constant variables
const int ROCK = 1, PAPER = 2, SCISSORS = 3;

// Function Prototypes
int computerChoice(int);
int getUserChoice(int);
void displayRandomNumber(int);
void winnerSelection(int, int, bool&);

using namespace std;

int main()
{
    int computer_choice=0, user_number=0;
    bool playAgain = 0;
    do
    {
        computer_choice = computerChoice(computer_choice);
        user_number = getUserChoice(user_number);
        displayRandomNumber(computer_choice);
        winnerSelection(computer_choice, user_number, playAgain);
    } while (playAgain == 1);

} // END int main()

int computerChoice(int computer_choice)
{
    unsigned seed = time(0);

    srand(seed); 

    // Random number
    return (rand() % (SCISSORS - ROCK + 1)) + ROCK;
}

int getUserChoice(int choice)
{
    cout << "\nChoose 'rock', 'paper', or 'scissors'.\n"
        << "1. for rock\n2. for paper\n3. for scissors\n ";

    while (!(cin >> choice) || (choice < 1 || choice > 3))
    {
        cout << "Error! Invalid Choice.Enter choice again from(1,2 or 3).\n";
        cin.clear();
        cin.ignore(222, '\n');
    }

    return choice;
}

void displayRandomNumber(int computerChoice)
{
    cout << "\nComputer Choice = ";

    if (computerChoice == 1)
        cout << "Rock";
    else if (computerChoice == 2)
        cout << "Paper";
    else if (computerChoice == 3)
        cout << "Scissors";

    cout << endl;
}

void winnerSelection(int computerChoice, int choice, bool& play_again)
{
    cout << endl;

    if (computerChoice == ROCK)
    {
        if (choice == PAPER)
        {
            cout << "You win: (Paper covers the rock).\n";
            play_again = 0;
        }
        else if (choice == SCISSORS)
        {
            cout << "Computer wins: (Rock smashes the scissors).\n";
            play_again = 0;
        }
        else if (choice == ROCK)
        {
            cout << "Tie. Play again to determine the winner." << endl;
            play_again = 1;
        }
    }
    else if (computerChoice == PAPER)
    {
        if (choice == ROCK)
        {
            cout << "Computer wins: (Paper covers rock).\n";
            play_again = 0;
        }
        else if (choice == SCISSORS)
        {
            cout << "You win: (Scissors cuts paper).\n";
            play_again = 0;
        }
        else if (choice == PAPER)
        {
            cout << "Tie. Play again to determine the winner." << endl;
            play_again = 1;
        }
    }
    else if (computerChoice == SCISSORS)
    {
        if (choice == ROCK)
        {
            cout << "You win: (Rock smashes the scissors).\n";
            play_again = 0;
        }
        else if (choice == PAPER)
        {
            cout << "Computer wins: (Scissors cuts the paper).\n";
            play_again = 0;
        }
        else if (choice == SCISSORS)
        {
            cout << "Tie. Play again to determine the winner." << endl;
            play_again = 1;
        }
    }

    cout << endl;
}
