#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>

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
    int interval = 5;

    Cell board[n]{};

    Cell p1;
    Cell p2;
public:
    void game()
    {
        move();
      //  initBoard();
        std::cout << "\n\n";
        printBoard();
    }
      
    void initBoard()
    {

        board[9].number = 17;
        board[28].number = 14;

        board[29].symbol = 'G';
        board[28].symbol = 'v';
        board[22].symbol = ladder;
        board[17].symbol = ladder2;
        board[16].symbol = ladder;
        board[14].symbol = ladder;
        board[11].symbol = ladder2;
        board[9].symbol = '*';
        board[0].symbol = 'S';
    
        board[p1.number].symbol = 'A';

        p2.symbol = 'B';
    }
    // Array som teller opp i stigende rekkefølge.
    void printBoard2()
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
    void printBoard()
    {
        for (int i = 6; i > 0; i--)
        {
            if (i % 2 == 0)
            {
                for (int j = 1; j < 6; j++)
                {
                    std::cout << '|' << board[i * 5 - j].symbol;
                }
                std::cout << "|";
            }
            else
            {
                for (int j = 0; j < 6; j++)
                {
                    std::cout << '|' << board[((i - 1) * 5) + j].symbol;
                }
            }
            std::cout << "\n";
        }
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

        p1.number += move;

        if (p1.number >= n-1)
        {
            exit(1);
        }
       
    /*    if (board[p1.number].number == board[9].number)
        {
            p1.number = board[p1.number].number;
        }
        else if(board[p1.number].number == board[28].number)
        {
            p1.number = board[p1.number].number;
        } */
    }

    void throwAndMove()
    {
        throwDie();
        move();
        printBoard();
    }

    void play()
    {

    }

    void makeLadder(int length)
    {

    }

    void makeChute(int length)
    {

    }

    void initRandomBoar()
    {
        //makeLadder();
       // makeChute();
    }
};

int main()
{
    srand(static_cast<unsigned int>(std::time(nullptr)));

    Laddergame l;

    l.game();

    try
    {
        throw 20;
    }
    catch (int e)
    {
        std::cout << e << "\n";
    }
}

