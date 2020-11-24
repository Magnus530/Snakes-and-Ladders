#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <vector>

class Laddergame
{
public:
    char ladder = '\\', ladder2 = '/';

    struct Cell
    {
        char symbol;
        int number;
    };

    static constexpr int n = 30;

    int vRow = 6, vCol = 5;

    std::vector<std::vector<int>> coord(vRow, vCol);

    Cell board[n]{};

    Cell p1{'A', 0};
    Cell p2{'B', 0};
public:
    void throwAndMove()
    {
        initBoard();

        while (true)
        {
            printBoard1();
            system("pause");
            system("cls");
            printBoard2();
            move();
        }
    }
      
    void initBoard()
    {
        board[29].symbol = 'G';
        board[28].symbol = 'v';
        board[22].symbol = ladder;
        board[17].symbol = ladder2;
        board[16].symbol = ladder;
        board[14].symbol = ladder;
        board[11].symbol = ladder2;
        board[9].symbol = '*';
        board[0].symbol = 'S';

        for (int i = 0; i < n - 1; i++)
        {
            board[i].number = i;
        }
    }
    // Array som teller opp i stigende rekkefølge.
    void printBoard99()
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                std::cout << '|' << board[i * 5 + j].symbol;
            }
            std::cout << '|' << "\n";
        }
    }
    // Array som teller ned i synkende rekkefølge, med alternerende rekker, først mot høyre så mot venstre.

    void printBoard1()
    {
        for (int i = 5; i >= 0; i--)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (p1.number == board[i * 5 + j].number)
                    {
                        std::cout << '|' << p1.symbol;
                    }
                    else
                    {
                        std::cout << '|' << board[i * 5 + j].symbol;
                    }
                }
                std::cout << "|";
            }
            else
            {
                for (int j = 4; j >= 0; j--)
                {
                    if (p1.number == board[i * 5 + j].number)
                    {
                        std::cout << '|' << p1.symbol;
                    }
                    else
                    {
                        std::cout << '|' << board[i * 5 + j].symbol;
                    }
                }
                std::cout << "|";
            }
            std::cout << "\n";
        }
    }

    void printBoard2()
    {
        for (int i = 5; i >= 0; i--)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (p2.number == board[i * 5 + j].number)
                    {
                        std::cout << '|' << p2.symbol;
                    }
                    else
                    {
                        std::cout << '|' << board[i * 5 + j].symbol;
                    }
                }
                std::cout << "|";
            }
            else
            {
                for (int j = 4; j >= 0; j--)
                {
                    if (p2.number == board[i * 5 + j].number)
                    {
                        std::cout << '|' << p2.symbol;
                    }
                    else
                    {
                        std::cout << '|' << board[i * 5 + j].symbol;
                    }
                }
                std::cout << "|";
            }
            std::cout << "\n";
        }
    }

    void makeCoords()
    {

    }

    void printNumb()
    {
        int p = 0;

        // 29-25
        for (int i = 0; i < 5; i++)
        {
            board[i].number = i + 29 - p;
            p += 2;
            std::cout << board[i].number;
        }
        p = 0;
        std::cout << "\n";

        // 20 -24
        for (int i = 5; i < 10; i++)
        {
            board[i].number = i + 15;
            std::cout << board[i].number;
        }
        std::cout << "\n";

        // 19-15
        for (int i = 10; i < 15; i++)
        {
            board[i].number = i + 9 - p;
            p += 2;
            std::cout << board[i].number;
        }
        p = 0;
        std::cout << "\n";

        // 10 -14
        for (int i = 15; i < 20; i++)
        {
            board[i].number = i - 5;
            std::cout << board[i].number;
        }
        std::cout << "\n";

        // 9-5   20-24
        for (int i = 20; i < 25; i++)
        {
            board[i].number = i - 11 - p;
            p += 2;
            std::cout << "0" << board[i].number;
        }
        p = 0;
        std::cout << "\n";

        //   0 -4
        for (int i = 25; i < 30; i++)
        {
            board[i].number = i - 25;
            std::cout << "0" << board[i].number;
        }
    }

    int throwDie()
    {   
        return(rand() % 6 + 1);
    }

    void move()
    {
        int move = throwDie();
        int move2 = throwDie();

        p1.number += move;
        p2.number += move2;

        if (p1.number >= n-1)
        {
            p1.number = 0;
        }
        else if (p2.number >= n - 1)
        {
            p2.number = 0;
        }

        if (p1.number == board[9].number)
        {
            p1.number = board[17].number;
        }
        else if(p1.number == board[28].number)
        {
            p1.number = board[14].number;
        }

        if (p2.number == board[9].number)
        {
            p2.number = board[17].number;
        }
        else if (p2.number == board[28].number)
        {
            p2.number = board[14].number;
        }
    }

    void play()
    {
      // throwAndMove();
       //initRandomBoard();
       //printBoard1();

        fillCoords();
       // printCoords();
    }

    void fillCoords()
    {
        for (int i = 0; i < vRow; i++)
        {
            for (int j = 0; j < vCol; j++)
            {
                coords[i][j] = j;
            }

            std::cout << std::endl;
        }
    }

    void printCoords()
    {
        for (int i = 0; i < coords.size(); i++)
        {
            for (int j = 0; j < coords[i].size(); j++)
            {
                std::cout << coords[i][j];
            }
            std::cout << std::endl;
        }
    }

    void makeLadder(int length)
    {
        int n = rand() % 3 + 25;

        if (n == 27 && length == 3)
        {
            board[n].symbol = ladder2;
            board[n - 6].symbol = ladder2;
            board[n - 8].symbol = '*';
        }
        else if (n == 26 && length == 3)
        {
            board[n].symbol = ladder2;
            board[n - 4].symbol = ladder2;
            board[n - 8].symbol = '*';
        }
        else if (n == 25 && length == 3)
        {
            board[n].symbol = ladder2;
            board[n - 2].symbol = ladder2;
            board[n - 8].symbol = '*';
        }

        if (n == 27 && length == 2)
        {
            board[n].symbol = ladder2;
            board[n - 6].symbol = '*';
        }
        else if (n == 26 && length == 2)
        {
            board[n].symbol = ladder2;
            board[n - 4].symbol = '*';
        }
        else if (n == 25 && length == 2)
        {
            board[n].symbol = ladder2;
            board[n - 2].symbol = '*';
        }
    }

    void makeChute(int length)
    {
        int n = rand() % 3 + 10;

        if (n == 10 && length == 3)
        {
            board[n].symbol = 'v';
            board[n - 2].symbol = ladder;
            board[n - 8].symbol = ladder;
        }
        else if (n == 11 && length == 3)
        {
            board[n].symbol = 'v';
            board[n - 4].symbol = ladder;
            board[n - 8].symbol = ladder;
        }
        else if (n == 12 && length == 3)
        {
            board[n].symbol = 'v';
            board[n - 6].symbol = ladder;
            board[n - 8].symbol = ladder;
        }

        if (n == 10 && length == 2)
        {
            board[n].symbol = 'v';
            board[n - 2].symbol = ladder;
        }
        else if (n == 11 && length == 2)
        {
            board[n].symbol = 'v';
            board[n - 4].symbol = ladder;
        }
        else if (n == 12 && length == 2)
        {
            board[n].symbol = 'v';
            board[n - 6].symbol = ladder;
        }
    }

    void initRandomBoard()
    {
        board[29].symbol = 'G';
        board[0].symbol = 'S';

        for (int i = 0; i < n - 1; i++)
        {
            board[i].number = i;
        }

        makeLadder(3);
        makeChute(3);
    }
};

int main()
{
    srand(static_cast<unsigned int>(std::time(nullptr)));

    Laddergame l;

    l.play();

}

