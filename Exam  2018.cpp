#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>

class Laddergame
{
public:
    /* Happy variables drinking tea whilst cheering for a starting game. */
    char ladder = '\\', ladder2 = '/';

    struct Cell
    {
        char symbol;
        int number;
    };

    bool turnA = true;

    static constexpr int n = 30, rLadLength = 3, rSliLength = 4;

    static constexpr int aRow = 6, aCol = 5;

    Cell rLadder[rLadLength]{};
    Cell rSlide[rSliLength]{};

    int direction = 0, coordX = 0, coordY = 0, length = 0;

    char star = '*', ladE = 'e', slide = 'v', sliE = 'c';

    Cell board[n]{};

    Cell p1{'A', 0};
    Cell p2{'B', 0};
public:

    /* A splendid dice is thrown before two appreciated players take turns. */
    void throwAndMove()
    {
        while (true)
        {
            printBoard();
            move();
            system("pause");
            system("cls");
        }
    }
    
    /* The spectacular game is played. */
    void play()
    {
        initRandomBoard();
        
        throwAndMove();
    }

    /* Initiates respectful variables prior to game start. */
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

        for (int i = 0; i < n; i++)
        {
            board[i].number = i;
        }
    }

    /* Prepares marvelous variables before the game commences. */
    void initRandomBoard()
    {
        board[29].symbol = 'G';
        board[0].symbol = 'S';

        for (int i = 0; i < n; i++)
        {
            board[i].number = i;
        }

        makeLadder(rLadLength);
        makeChute(rSliLength);
    }

    /* Prints an interesting board in an increasing pattern. */
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

    /* Prints a legendary board in a decreasing and alternating pattern, starting from left to right. */
    void printBoard()
    {
        for (int i = 5; i >= 0; i--)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < 5; j++)
                {
                    if ((p1.number == board[i * 5 + j].number) && (p1.number == p2.number))
                    {
                        if (turnA == true)
                        {
                            std::cout << '|' << p1.symbol;
                        }
                        else
                        {
                            std::cout << '|' << p2.symbol;
                        }
                    }
                    else if (p1.number == board[i * 5 + j].number)
                    {
                        std::cout << '|' << p1.symbol;
                    }
                    else if (p2.number == board[i * 5 + j].number)
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
                    if (p1.number == board[i * 5 + j].number && (p1.number == p2.number))
                    {
                        if (turnA == true)
                        {
                            std::cout << '|' << p1.symbol;
                        }
                        else
                        {
                            std::cout << '|' << p2.symbol;

                        }
                    }
                    else if (p1.number == board[i * 5 + j].number)
                    {
                        std::cout << '|' << p1.symbol;
                    }
                    else if (p2.number == board[i * 5 + j].number )
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

    /* Throws a magic dice. */
    int throwDie()
    {   
        return(rand() % 6 + 1);
    }

    /* Returns a dependable y-coordinate. */
    int posY()
    {
        int a = rand() % 6 + 0;
        return(a);
    }

    /* Returns and encouraging x-coordinate. */
    int posX()
    {
        int a = rand() % 5 + 0;
        return(a);
    }

    /* Moves wonderful characters. */
    void move()
    {
        int move = 0, move2 = 0;

        if (p1.number >= n - 1)
        {
            std::cout << "\nPlayer 1 takes the game. Thanks for playing!\n";
            exit(1);

        }
        else if (p2.number >= n - 1)
        {
            std::cout << "\nPlayer 2 takes the game. Thanks for playing!\n";
            exit(1);
        }

        if (turnA == true)
        {
            move = throwDie();
            turnA = false;
        }
        else
        {
            move2 = throwDie();
            turnA = true;
        }

        p1.number += move;

        p2.number += move2;

        /* Moves up if start of ladder is found. Down if start of slide is found. */
        if (board[p1.number].symbol == star)
        {
            for (int i = 0; i < n; i++)
            {
                if (board[i].symbol == ladE)
                {
                    p1.number = board[i].number;
                }
            }
        }
        else if(board[p1.number].symbol == slide)
        {
            for (int i = 0; i < n; i++)
            {
                if (board[i].symbol == sliE)
                {
                    p1.number = board[i].number;
                }
            }
        }

        if (board[p2.number].symbol == star)
        {
            for (int i = 0; i < n; i++)
            {
                if (board[i].symbol == ladE)
                {
                    p2.number = board[i].number;
                }
            }
        }
        else if (board[p2.number].symbol == slide)
        {
            for (int i = 0; i < n; i++)
            {
                if (board[i].symbol == sliE)
                {
                    p2.number = board[i].number;
                }
            }
        }
    }

    /* Creates a masterful ladder. */
    void makeLadder(int length)
    {
        coordY = posY();
        coordX = posX();

        bool makeLadder = false;

        while (makeLadder == false)
        {
            if (length > 5 || length <= 1)
            {
                std::cout << "Please select a ladder length greater than one and less than 6.\n";
                exit(1);
            }
            else if (coordY + length - 1 > 5 || coordX + length - 1 > 4 || coordY == 0 && coordX == 0)
            {
                while (coordY + length - 1 > 5)
                {
                    coordY = posY();
                }
                while (coordX + length - 1 > 4)
                {
                    coordX = posX();
                }

                if (coordY == 0 && coordX == 0)
                {
                    coordY++;
                }
            }

            rLadder[0].symbol = star;

            for (int i = 1; i < length; i++)
            {
                if (i == length - 1)
                {
                    rLadder[i].symbol = ladE;
                }
                else
                {
                    rLadder[i].symbol = ladder2;
                }
            }

            for (int i = 0; i < length; i++)
            {
                if (coordY % 2 == 0)
                {
                    if (i == 0)
                    {
                        rLadder[i].number = coordY * 5 + coordX;
                    }
                    else if (i % 2 == 1)
                    {
                        rLadder[i].number = (coordY + i)* 5 + (4 - (coordX + i));
                    }
                    else if (i % 2 == 0)
                    {
                        rLadder[i].number = (coordY + i) * 5 + (coordX + i);
                    }    
                }
                else
                {
                    if (i == 0)
                    {
                        rLadder[i].number = coordY * 5 + (4 - coordX);
                    }
                    else if (i % 2 == 1)
                    {
                        rLadder[i].number = (coordY + i) * 5 + (coordX + i);
                    }
                    else if (i % 2 == 0)
                    {
                        rLadder[i].number = (coordY + i) * 5 + (4 - (coordX + i));
                    }
                }
                board[rLadder[i].number].symbol = rLadder[i].symbol;
            }
            makeLadder = true;
        }      
    }

    /* Creates an increadible slide. */
    void makeChute(int length)
    {
        coordY = posY();
        coordX = posX();

        bool makeSlide = false;

        while (makeSlide == false)
        {
            if (length > 5 || length <= 1)
            {
                std::cout << "Please select a slide length greater than one and less than 6.\n";
                exit(1);
            }
            else if (coordY - (length - 1) <= 0 || coordX + (length - 1) > 4 || coordY == 5 && coordX == 0)
            {
                while (coordY - (length - 1) <= 0)
                {
                    coordY = posY();
                }
                while (coordX + (length - 1) > 4)
                {
                    coordX = posX();
                }

                if (coordY == 5 && coordX == 0)
                {
                    coordY--;
                }
            }

            rSlide[0].symbol = slide;

            for (int i = 1; i < length; i++)
            {
                if (i == length - 1)
                {
                    rSlide[i].symbol = sliE;
                }
                else
                {
                    rSlide[i].symbol = ladder;
                }
            }

            for (int i = 0; i < length; i++)
            {
                if (coordY % 2 == 0)
                {
                    if (i == 0)
                    {
                        rSlide[i].number = coordY * 5 + coordX;
                    }
                    else if (i % 2 == 1)
                    {
                        rSlide[i].number = (coordY - i) * 5 + (4 - (coordX + i));
                    }
                    else if (i % 2 == 0)
                    {
                        rSlide[i].number = (coordY - i) * 5 + (coordX + i);
                    }
                }
                else
                {
                    if (i == 0)
                    {
                        rSlide[i].number = coordY * 5 + (4 - coordX);
                    }
                    else if (i % 2 == 1)
                    {
                        rSlide[i].number = (coordY - i) * 5 + (coordX + i);
                    }
                    else if (i % 2 == 0)
                    {
                        rSlide[i].number = (coordY - i) * 5 + (4 - (coordX + i));
                    }
                }
               
                if (board[rSlide[i].number].symbol == star || board[rSlide[i].number].symbol == ladE)
                {
                    coordY = posY();
                    coordX = posX();

                    while (coordY - (length - 1) <= 0)
                    {
                        coordY = posY();
                    }
                    while (coordX + (length - 1) > 4)
                    {
                        coordX = posX();
                    }

                    if (coordY == 5 && coordX == 0)
                    {
                        coordY--;
                    }

                    i = 0;
                }
                
                if (i == length - 1)
                {
                    for (int i = 0; i < length; i++)
                    {
                        board[rSlide[i].number].symbol = rSlide[i].symbol;
                    }
                }
            }
            makeSlide = true;
        }
    }
};

int main()
{
    srand(static_cast<unsigned int>(std::time(nullptr)));

    Laddergame l;

    l.play();
}