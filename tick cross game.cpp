#include <iostream>
using namespace std;
// global variables.................................................................
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char turn = 'X';
bool draw = false;
////////////////////////////////////////////////////////////////////////////////////////
void display_board()
{
    system("cls"); // Use system("clear"); on Unix/Linux systems
    cout << "\n\n\t\t\t____________________________\n";
    cout << "\n\t\t\tT I C K  C R O S S   G A M E\n";
    cout << "\t\t\t____________________________\n";
    cout << "\tPlayer1 [X]\n\tPlayer2 [O]";
    cout << "\n\t\t\t     |     |     ";
    cout << "\n\t\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  ";
    cout << "\n\t\t\t_____|_____|_____";
    cout << "\n\t\t\t     |     |     ";
    cout << "\n\t\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  ";
    cout << "\n\t\t\t_____|_____|_____";
    cout << "\n\t\t\t     |     |     ";
    cout << "\n\t\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  ";
    cout << "\n\t\t\t     |     |     " << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////
void player_turn()
{
    int choice;
    if (turn == 'X')
    {
        cout << "\tPlayer1 [X] turn: ";
    }
    else if (turn == 'O')
    {
        cout << "\tPlayer2 [O] turn: ";
    }
    cin >> choice;

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
        cout << "\t!!!Invalid Choice.....\a" << endl;
        player_turn();
        break;
    }
    ////////////////////////
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "\n\tBOX Already Filled!!!!!!......Try Again!!!!!!.....\a\n\n";
        player_turn();
    }
}
///////////////////////////////////////////////////////////////////////////////////////
bool check_win()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return true;
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return true;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    draw = true;
    return true;
}
///////////////////////////////////////////////////////////////////////////////////
void reset_board()
{
    char num = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = num++;
        }
    }
    turn = 'X';
    draw = false;
}
///////////////////////////////////////////////////////////////////////////////////
int main()
{
    bool choice;
    do
    {
        reset_board();
        while (!check_win())
        {
            display_board();
            player_turn();
        }
        display_board();

        if (turn == 'X' && draw == false)
            cout << "\n\t\tPlayer2 [O] Wins....Congratulations!..........\n";
        else if (turn == 'O' && draw == false)
            cout << "\n\t\tPlayer1 [X] Wins....Congratulations!..........\n";
        else
            cout << "\n\t\tIt's a Draw!!..........\n";

        cout << "\n\tPress 0 to exit \n\tPress 1 to play again  ";
        cin >> choice;

    } while (choice == 1);
    cout<<"\n\t\t\t\a________________________\n";
    cout << "\n\t\t\t!!!G A M E  E N D E D!!!\n";
    cout<<"\t\t\t________________________"<<endl;
    return 0;
}
