#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

string board[3][3];
string SymbolPlayer1 = "X";
string SymbolPlayer2 = "O";
string EmptySymbol = "-";

int turn = 1;
bool win = false;
bool empt = true;

void pause()
{
    float pausa;
    cout << "\nPress 0 to exit" << endl;
    cin >> pausa;
}

void vaciarTablero()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = EmptySymbol;
        }
    }
}

void DrawBoard()
{
    system("CLS");
    cout << "        0       1       2        " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i;
        for (int j = 0; j < 3; j++)
        {
            cout << "   |   " << board[i][j];
        }
        cout << endl;
    }
}

void CheckRows()
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1]) & (board[i][1] == board[i][2]) & (board[i][2] != EmptySymbol))
        {
            if (turn == 1)
            {
                cout << "********************** Player O Won **********************" << endl;
                pause();
                exit(0);
            }
            else
            {
                cout << "********************** Player X Won **********************" << endl;
                pause();
                exit(0);
            }
        }
    }
}

void CheckColumns()
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[0][i] == board[1][i]) & (board[1][i] == board[2][i]) & (board[1][i] != EmptySymbol))
        {
            if (turn == 1)
            {
                cout << "********************** Player O Won **********************" << endl;
                pause();
                exit(0);
            }
            else
            {
                cout << "********************** Player X Won **********************" << endl;
                pause();
                exit(0);
            }
        }
    }
}

void CheckDiagonal()
{
    if ((board[0][0] == board[1][1]) & (board[1][1] == board[2][2]) & (board[1][1] != EmptySymbol))
    {
        if (turn == 1)
        {
            cout << "********************** Player O Won **********************" << endl;
            pause();
            exit(0);
        }
        else
        {
            cout << "********************** Player X Won **********************" << endl;
            pause();
            exit(0);
        }
    }
    if ((board[0][2] == board[1][1]) & (board[1][1] == board[2][0]) & (board[1][1] != EmptySymbol))
    {
        if (turn == 1)
        {
            cout << "********************** Player O Won **********************" << endl;
            pause();
            exit(0);
        }
        else
        {
            cout << "********************** Player X Won **********************" << endl;
            pause();
            exit(0);
        }
    }
}

void CheckTie() {
    empt = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == EmptySymbol) {
                empt = true;
                break;
            }
        }
        if (empt == true) {
            break;
        }
        cout << endl;
    }
}

void CheckWin()
{
    CheckRows();
    CheckColumns();
    CheckDiagonal();
    CheckTie();
    if (empt == false) {
        cout << "*********** Tie *************" << endl;
        int revancha;
        cout << "Press 1 if you want revenge or 2 if not" << endl;
        cin >> revancha;
        if (revancha == 1) {
            vaciarTablero();
            turn = 1;
            DrawBoard();
        }
        else {
            cout << "Game over" << endl;
            pause();
            exit(0);
        }
    }
}

void CheckPosition(int row, int column)
{
    if ((row >= 0 & row <= 2) & (column >= 0 & column <= 2))
    {
        if (board[row][column] == EmptySymbol)
        {
            if (turn == 1)
            {
                board[row][column] = SymbolPlayer1;
                turn = 2;
                DrawBoard();
            }
            else
            {
                board[row][column] = SymbolPlayer2;
                turn = 1;
                DrawBoard();
            }
        }
        else
        {
            cout << "Occupied coordinate" << endl;
            cout << "Type the Row: ";
            cin >> row;
            cout << "Type the Column: ";
            cin >> column;
            CheckPosition(row, column);
        }
    }
    else
    {
        while (!((row >= 0 & row <= 2) & (column >= 0 & column <= 2)))
        {
            cout << "Invalid coordinate" << endl;
            cout << "Type the Row: ";
            cin >> row;
            cout << "Type the Column: ";
            cin >> column;
        }
        if (board[row][column] == EmptySymbol)
        {
            if (turn == 1)
            {
                board[row][column] = SymbolPlayer1;
                turn = 2;
                DrawBoard();
            }
            else
            {
                board[row][column] = SymbolPlayer2;
                turn = 1;
                DrawBoard();
            }
        }
        else
        {
            cout << "Occupied coordinate" << endl;
            cout << "Type the Row: ";
            cin >> row;
            cout << "Type the Column: ";
            cin >> column;
            CheckPosition(row, column);
        }
    }
}

int main(int argc, char* argv[])
{
    int row;
    int column;
    vaciarTablero();
    DrawBoard();
    while (!win)
    {
        cout << "\nEnter the coordinate to put your symbol" << endl;
        cout << "Type the Row: ";
        cin >> row;
        cout << "Type the Column: ";
        cin >> column;
        CheckPosition(row, column);
        CheckWin();
    }
    return 0;
}