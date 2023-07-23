#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentPlayer = 'X';

void displayBoard()
{
     system("cls");
  char name1[100];
  char name2[100];
    
    cout << "Player 1 (X) - "<<name1<<"  Player 2 (O) - "<<name2<<endl;
    cout << "\t\t\t\t     |     |     " << endl;
    cout << "\t\t\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "\t\t\t\t_____|_____|_____" << endl;
    cout << "\t\t\t\t     |     |     " << endl;
    cout << "\t\t\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "\t\t\t\t_____|_____|_____" << endl;
    cout << "\t\t\t\t     |     |     " << endl;
    cout << "\t\t\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "\t\t\t\t     |     |     " << endl << endl;
}

bool checkWin()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return true;
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
        return true;

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

bool placeMark(int choice)
{
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentPlayer;
        return true;
    }

    return false;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main()
{
    int choice;
    bool gameEnd = false;
    char name1[100];
    char name2[100];
    cout<<"\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\tWelcome to the ultimate battle of wits and strategy,The classic game of Tic Tac Toe!"<<endl;
    cout<<"\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t T I C - O - T A C - X - T O E"<<endl;
    cout<<"\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"\t\tPlease enter your name - Player 1: ";
    cin>>name1;
    cout<<endl;
    cout<<"\t\tPlease enter your name - Player 2: ";
    cin>>name2;
    cout<<endl;
    cout<<"\t\t Ready players!  "<<name1<<"- [X] and "<<name2<<"- [O] "<<endl;
    cout<<endl;
    cout<<"\t\t Here's the Battle Ground"<<endl;
    cout<<endl;
    while (!gameEnd)
    {
        displayBoard();

        cout << "\t\tPlayer " << currentPlayer << ", enter a number (1-9): ";
        cin >> choice;

        if (choice < 1 || choice > 9)
        {
            cout << "\t\tInvalid input. Please try again." << endl;
            continue;
        }

        if (!placeMark(choice))
        {
            cout << "\t\tCell already taken. Please try again." << endl;
            continue;
        }

        if (checkWin())
        {
            displayBoard();
            cout<<"\t\t--------------------------------"<<endl;
            cout << "\t\t Player " << currentPlayer << " wins! Congratulations!" << endl;
            cout<<"\t\t--------------------------------"<<endl;
            gameEnd = true;
        }
        else if (checkDraw())
        {
            displayBoard();
            cout<<"\t\t--------------------------------"<<endl;
            cout << "\t\t |It's a draw! Good game! |" << endl;
            cout<<"\t\t--------------------------------"<<endl;
            gameEnd = true;
        }
        else
        {
            switchPlayer();
        }
    }

    return 0;
}