#include <iostream>
using namespace std;

// base player class. Polymorphism concept --> virtual Functions
class Player
{
protected:
    char symbol;

public:
    Player(char sym) : symbol(sym) {}
    virtual void makeMove(class Board &board) = 0;
    char getSymbol() const
    {
        return symbol;
    }
};

// Board class. Encapsulation.
class Board
{
private:
    char board[3][3];
    bool draw;

public:
    Board()
	{ 
		resetBoard();
	}

    // To reset the board to its original state
    void resetBoard()
    {
        char num = '1';
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = num++;
            }
        }
        draw = false;
    }

    // To display current state of board
    void displayBoard()
    {
        system("cls"); // For Unix/Linux, use system("clear");
        cout << "\n\n\t\t\t____________________________\n";
        cout << "\n\t\t\tT I C K  C R O S S   G A M E\n";
        cout << "\t\t\t____________________________\n";
        cout << "\tPlayer1 [X]\n\tPlayer2 [O]";
        for (int i = 0; i < 3; i++)
        {
            cout << "\n\t\t\t  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "  ";
            if (i < 2)
                cout << "\n\t\t\t_____|_____|_____";
            else
                cout << "\n\t\t\t     |     |     ";
        }
        cout << endl;
    }

    // set the specific symbol X or O to the board
    bool setMove(int row, int column, char symbol)
    {
        if (board[row][column] != 'X' && board[row][column] != 'O')
        {
            board[row][column] = symbol;
            return true;
        }
        return false;
    }

    //
    bool checkWin()
    {
        // check win in a row or column
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
                return true;
            if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
                return true;
        }
        // check win diagonally
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
            return true;
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
            return true;

        // check if any box left behind without a try
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
            }
        }

        // set draw to true
        draw = true;
        return true;
    }

    // returns draw
    bool isDraw()
    {
        return draw;
    }
};

// derived class of player. Inheritance.
class HumanPlayers : public Player
{
public:
    HumanPlayers(char s) : Player(s) {}
    void makeMove(Board &board)
    {
        int row, column, choice;
        bool validMove = false;
        while (!validMove)
        {
            cout << "Player [" << symbol << "] turn: ";
            cin >> choice;
            // Process valid move
            switch (choice)
            {
            case 1:
                row = 0;
                column = 0;
                break;
            case 2:
                row = 0;
                column = 1;
                break;
            case 3:
                row = 0;
                column = 2;
                break;
            case 4:
                row = 1;
                column = 0;
                break;
            case 5:
                row = 1;
                column = 1;
                break;
            case 6:
                row = 1;
                column = 2;
                break;
            case 7:
                row = 2;
                column = 0;
                break;
            case 8:
                row = 2;
                column = 1;
                break;
            case 9:
                row = 2;
                column = 2;
                break;
            default:
                cout << "Invalid Move! Please enter a number between 1 and 9.\n";
                continue;
            }

            if (board.setMove(row, column, symbol))
                validMove = true;
            else
                cout << "Box already filled! Try another move...\n";
        }
    }
};

// Game Playing class. Composition and Abstraction
class Game
{
private:
    Board board;
    Player *player1;
    Player *player2;
    Player *currentPlayer;
    static int gameCount; // Static variable to count number of games

public:
    Game(Player *p1, Player *p2) : player1(p1), player2(p2)
    {
        currentPlayer = player1;
        gameCount++; // Increment the game count when a new game is started
    }

    static int getGameCount() // Static function to return the count of games
    {
        return gameCount;
    }

    void switchPlayer()
    {
        if (currentPlayer == player1)
            currentPlayer = player2;
        else
            currentPlayer = player1;
    }

    // The Game Loop
    void play()
    {
        bool playAgain;
        do
        {
            board.resetBoard();
            while (!board.checkWin())
            {
                board.displayBoard();
                currentPlayer->makeMove(board);
                switchPlayer();
            }
            board.displayBoard();
            announceResult();

            cout << "\n\tPress 0 to exit, 1 to play again: ";
            cin >> playAgain;
        } while (playAgain);
    }

    // Result Announcement
    void announceResult()
    {
        if (!board.isDraw())
        {
            switchPlayer(); // Get the winning player back
            cout << "\n\t\tPlayer [" << currentPlayer->getSymbol() << "] wins. Congratulations!\n";
        }
        else
        {
            cout << "\n\t\tIt's a draw!\n";
        }
    }
};

// Initialize the static variable
int Game::gameCount = 0;

int main()
{
    Player *P1 = new HumanPlayers('X');
    Player *P2 = new HumanPlayers('O');

    Game game(P1, P2);
    game.play();

    // Show how many games have been played
    cout << "\n\tNumber of games played: " << Game::getGameCount() << endl;

    delete P1;
    delete P2;

    cout << "\n\t\t\t*** Game Ended ***" << endl;
    return 0;
}
