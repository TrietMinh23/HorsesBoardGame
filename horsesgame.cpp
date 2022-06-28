#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

// Ham ho tro giao dien.
void printHorizontalLine (int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << " -------";
    }
    cout << endl;
}

// Ham ho tro giao dien.
void printVerticalLine (int size)
{
    for (int i = 0; i < size + 1; ++i)
    {
        cout << "|       ";
    }
    cout << endl;
}

// Ham ho tro giao dien.
void setBoard (char board[][4], char name[][4], int pos[], int size, int players, int horses)
{
    
    for (int i = 0; i < size * size; i++)
    {
        memcpy(board[i], "   ", 4);
    }

    for (int i = 0; i < players * horses; i++)
    {
        memcpy(board[pos[i]], name[i], 4);
    }
}

// Ham ho tro giao dien.
void printBoard (char board[][4], int size, char name[][4], int pos[], int map[][50])
{
    for (int i = 0; i < size; i++)
    {
        printHorizontalLine(size);
        printVerticalLine(size);

        cout << "|";
        for (int j = 0; j < size; j++)
        {
            cout << "  " << board[map[i][j]] << "  |";
        }
        cout << endl;
        printVerticalLine(size);
    }
    printHorizontalLine(size);
}

// Ham ho tro chuc nang Game.
void setting (int &size, int &players, int &horses, int &rangeNumber)
{
    cout << "Welcome To The Horse Board Game." << endl;
    cout << "Set board game size (x*x; x = 3, 5 or 7): ";
    cin >> size;
    cout << "Set the number of players (1, 2 or 3): ";
    cin >> players;
    cout << "Set the number of horses of each players (1, 2 or 3): ";
    cin >> horses;
    cout << "Set the range of randomized dice rolls: ";
    cin >> rangeNumber;
}

// Ham ho tro chuc nang game.
void namePlayer (int players, char name[][4], int horses)
{
    string playerName;
    char nameTemp[players][4];
    for (int i = 0; i < players; i++)
    { 
        cout << "Enter the players name " << i + 1 << " (3 characters): ";
        cin >> playerName;
        for (int j = 0; j < 4; j++)
        {
            nameTemp[i][j] = playerName[j];
        }
    }
    int n = 0;
    for (int i = 0; i < players * horses; i++)
    {
            memcpy(name[i], nameTemp[n], 4);
            ++n;
            if (((players == 3 && horses == 3) || (players == 2 && horses == 2)) &&  n == horses) n = 0;
            else if (players == 2  && horses == 3 && n == horses - 1) n = 0;
            else if (players == 3 && horses == 2 && n == horses + 1) n = 0;
            else if (players == 1 && horses <= 3) n = 0;
    }
}

// Ham thuc thi Game.
int playGame (char board[][4], char name[][4], int pos[], int size, int players, int rangeNumber, int horses, int map[][50])
{
    int move;
    int winner = -1;
    int n = rangeNumber;
    while (winner == -1)
    {
        for (int i = 0; i < players * horses; i++)
        {
            move = rand() % n + 1;
            cout << name[i] << " (" <<  (int)(i / players) + 1 << ") " << " rolled into " << move << endl;
            if (pos[i] + move > size * size - 1)
            {
                cout << name[i] << " cannot move forward" << endl;
            }
            else
            {
                pos[i] = pos[i] + move;
                if (pos[i] == size * size - 1)
                {
                    winner = i;
                    break;
                }
                for (int j = 0; j < players * horses; j++)
                {
                    if (pos[i] == pos[j] && (i % players) == (j % players) && pos[i] != -1 && i != j)
                    {
                        cout << name[i] << " (" <<  (int)(i / players) + 1 << ") " << " cannot move forward " << endl;
                        pos[i] -= move;
                    }
                    else if (pos[i] == pos[j]  && i != j && pos[i] != -1)
                    {
                        pos[j] = -1;
                        cout << name[i] << " kicked " << name[j] << endl;
                    }
                }
            }
            setBoard(board, name, pos, size, players, horses);
            printBoard(board, size, name, pos, map);
            getch();
        }
    }
    setBoard(board, name, pos, size, players, horses);
    printBoard(board, size, name, pos, map);
    cout << name[winner] << " is the winner" << endl;
    return winner;
}

// Ham in ket qua.
void Match(int &numOfGame, int players, int playerWinner, char name[][4], int NUGame[])
{
    numOfGame++;
    cout << "Total number of match: " << numOfGame << endl;
    ;
    for (int i = 0; i < players; i++)
    {
        if (playerWinner % 3 == i)
        {
            NUGame[i] += 1;
        }
        cout << name[i] << " win " << NUGame[i] << " match. " << (NUGame[i] /  (1.0 *numOfGame))  * 100 << "% win." << endl;
    }
}

// Ham dat vi tri con ngua.
void setPos(int players,int horses, int pos[])
{
    for (int i = 0; i < players * horses; i++)
    {
        pos[i] = -1;
    }
}

// Ham chon map.
void chooseMap (int size, int map[][50])
{
    int a;
    int map1[5][50] = {{0, 1, 2, 3 , 4}, {5, 6, 7, 8, 9}, {10, 11, 12, 13, 14}, {15, 16, 17, 18, 19}, {20, 21, 22, 23, 24}};
    int map2[7][50] = {{0, 1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12, 13}, {14, 15, 16, 17, 18, 19, 20}, {21, 22, 23, 24, 25, 26, 27}, {28, 29, 30, 31, 32, 33, 34}, {35, 36, 37, 38, 39, 40, 41}, {41, 43, 44, 45, 46, 47, 48}};
    int map3[3][50] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    int map4[5][50] = {{0, 1, 2, 3, 4}, {15, 16, 17, 18, 5}, {14, 23, 24, 19, 6}, {13, 22, 21, 20, 7}, {12, 11, 10, 9, 8}};
    int map5[7][50] = {{0, 1, 2, 3, 4, 5, 6}, {23, 24, 25, 26, 27, 28, 7}, {22, 39, 40, 41, 42, 29, 8}, {21, 38, 47, 48, 43, 30, 9}, {20, 37, 46, 45, 44, 31, 10}, {19, 36, 35, 34, 33, 32, 11}, {18, 17, 16, 15, 14, 13, 12}};
    int map6[3][50] = {{0, 1, 2}, {7, 8, 3}, {6, 5, 4}};
    int map7[5][50] = {{0, 1, 2, 3, 4}, {9 ,8 ,7 ,6, 5}, {10, 11, 12, 13, 14}, {19 ,18, 17, 16, 15}, {20, 21, 22, 23, 24}};
    int map8[7][50] = {{0, 1, 2, 3, 4, 5, 6}, {13, 12, 11, 10, 9, 8, 7}, {14, 15, 16, 17, 18, 19, 20}, {27, 26, 25, 24, 23, 22, 21}, {28, 29, 30, 31, 32, 33, 34}, {41, 40, 39, 38, 37, 36, 35}, {42, 43, 44, 45, 46, 47, 48}};
    int map9[3][50] = {{0, 1, 2}, {5, 4, 3}, {6, 7, 8}};
    cout << "Map 1: Normal Map." << endl;
    cout << "Map 2: Spiral Map." << endl;
    cout << "Map 3: ZiZag Map." << endl;
    cout << "Choose (1, 2, or 3): ";
    cin >> a;
    if (a == 1)
    {
        if (size == 5)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    map[i][j] = map1[i][j];
                }
            }
        }
        else if (size == 7)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    map[i][j] = map2[i][j];
                }
            }
        }
        else if(size == 3)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    map[i][j] = map3[i][j];
                }
            }
        }
    }
    if (a == 2)
    {
        if (size == 5)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    map[i][j] = map4[i][j];
                }
            }
        }
        else if (size == 7)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    map[i][j] = map5[i][j];
                }
            }
        }
        else if(size == 3)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    map[i][j] = map6[i][j];
                }
            }
        }
    }
    if (a == 3)
    {
        if (size == 5)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    map[i][j] = map7[i][j];
                }
            }
        }
        else if (size == 7)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    map[i][j] = map8[i][j];
                }
            }
        }
        else if(size == 3)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    map[i][j] = map9[i][j];
                }
            }
        }
    }
}

// Ham chon mau sax.
int chooseColor()
{
    int n;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 192);
    cout << "Color: 192 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
    cout << "Color: 160 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 80);
    cout << "Color: 80 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "Color: 11 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "Color: 2 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "Color: 7 ";
    cout << endl;
    cout << "Choose colors: ";
    cin  >> n;
    return n;
}

// Ham choi lai.
bool gameReplay(bool start)
{
    char c;
    cout << "Do you want to play game again (Y/N)?: ";
        cin >> c;
        switch(c)
        {
            case 'Y':
            case 'y':
            {
                start = true;
                break;
            }
            case 'N':
            case 'n':
            {
                start = false;
                break;
            }
        }
    return start;
}
// -------------------------------------------------------------------
int main()
{
    int size = -1, players = -1, horses = -1, rangeNumber = -1, playerWinner;

    srand(time(0));
    setting(size, players, horses, rangeNumber);
    int map[size][50];
    char name[players * horses][4];
    namePlayer(players, name, horses);
    int pos[players * horses] = {};
    setPos(players, horses, pos);

    char board[size * size][4];
    int numOfGame = 0;
    int NUGame[players] = {0};
    bool start = true;
    while (start)
    {  
        setPos(players, horses, pos);
        chooseMap(size, map);
        int n = chooseColor();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
        playerWinner = playGame (board, name, pos, size, players, rangeNumber, horses, map);
        Match(numOfGame, players, playerWinner, name, NUGame);
        start = gameReplay(start);
    }
    
    return 0;
}