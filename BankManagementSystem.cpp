#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////
class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    long double balance;

public:
    BankAccount(int an, string ahn, long double bal)
        : accountNumber(an), accountHolderName(ahn), balance(bal) {}

    int get_accountNumber() { return accountNumber; }
    string get_accountHolderName() { return accountHolderName; }
    long double get_balance() { return balance; }

    void deposit(long double amount)
    {
        balance += amount;
    }

    void withdraw(long double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "\n\t\t\t< I N S U F F I C I E N T  B A L A N C E >";
        }
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////
class BankManagement
{
private:
    vector<BankAccount> accounts;

public:
    void add_account(int ann, string ahnn, long double ball)
    {
        accounts.push_back(BankAccount(ann, ahnn, ball));
    }

    void ShowAllAccounts()
    {
        cout << "\n\t\t\t< A L L  A C C O U N T S >";
        cout << "\n\t\t\t******************************************************************";
        for (size_t i = 0; i < accounts.size(); i++)
        {
            cout << "\n\t\t\tName:           " << accounts[i].get_accountHolderName() << endl;
            cout << "\t\t\tAccount Number: " << accounts[i].get_accountNumber() << endl;
            cout << "\t\t\tTotal Balance:  " << accounts[i].get_balance() << endl;
            cout << "\n\t\t\t******************************************************************";
        }
    }

    void SearchAccount(int actn)
    {
        cout << "\n\t\t\t< A C C O U N T  D E T A I L S >";
        cout << "\n\t\t\t******************************************************************";
        bool found = false;
        for (size_t i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].get_accountNumber() == actn)
            {
                cout << "\n\t\t\tName:           " << accounts[i].get_accountHolderName() << endl;
                cout << "\t\t\tAccount Number: " << accounts[i].get_accountNumber() << endl;
                cout << "\t\t\tTotal Balance:  " << accounts[i].get_balance() << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "\n\n\t\t\t\t! ! !  I N V A L I D  A C C O U N T  N U M B E R  ! ! !\n";
        }
        cout << "\n\t\t\t******************************************************************";
    }

    BankAccount *FindAccount(int Accountnum)
    {
        for (size_t i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].get_accountNumber() == Accountnum)
            {
                return &accounts[i];
            }
        }
        return NULL; // Return NULL if account not found
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int choice;
    BankManagement bank;
    int op;

    // Main Menu.........................
    do
    {
        system("cls");
        cout << "\n\n\t\t\t_____________________________________________________________________________________________________________\n";
        cout << "\n\t\t\t\t\t\t\tB A N K   M A N A G E M E N T   S Y S T E M\n";
        cout << "\t\t\t_____________________________________________________________________________________________________________\n";
        cout << "\n\t\t\t< M A I N  M E N U >";
        cout << "\n\t\t\t__________________________________________________________________\n";
        cout << "\n\t\t\t1. Create New Account";
        cout << "\n\t\t\t2. Show All Accounts";
        cout << "\n\t\t\t3. Search Account";
        cout << "\n\t\t\t4. Deposit Money";
        cout << "\n\t\t\t5. WithDraw Money";
        cout << "\n\t\t\t6. Exit";
        cout << "\n\t\t\t__________________________________________________________________\n";
        cout << "\n\t\t\tPlease Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\n\t\t\t******************************************************************";
            int accountNum;
            cout << "\n\t\t\tEnter Account Number: ";
            cin >> accountNum;
            cin.ignore(); // Ignore the leftover newline character
            string accountHolderNam;
            cout << "\t\t\tEnter AccountHolder Name: ";
            getline(cin, accountHolderNam);
            long double balance;
            cout << "\t\t\tEnter Your Initial Balance: ";
            cin >> balance;
            bank.add_account(accountNum, accountHolderNam, balance);
            cout << "\n\t\t\t< A C C O U N T   C R E A T E D  S U C C E S S F U L L Y >" << endl;
            cout << "\n\t\t\t******************************************************************";
            break;
        }

        case 2:
            bank.ShowAllAccounts();
            break;

        case 3:
        {
            int acn;
            cout << "\n\t\t\tEnter your account number: ";
            cin >> acn;
            bank.SearchAccount(acn);
            break;
        }

        case 4:
        {
            int acn;
            long double amount;
            cout << "\n\t\t\t******************************************************************";
            cout << "\n\t\t\tEnter your account number: ";
            cin >> acn;
            BankAccount *account = bank.FindAccount(acn);
            if (account != NULL)
            {
                cout << "\n\t\t\tEnter the amount you want to deposit: ";
                cin >> amount;
                account->deposit(amount);
                cout << "\n\t\t\t< R.S " << amount << " D E P O S I T E D   S U C C E S S F U L L Y >";
            }
            else
            {
                cout << "\n\t\t\t< A C C O U N T  N O T  F O U N D >";
            }
            cout << "\n\t\t\t******************************************************************";
            break;
        }

        case 5:
        {
            int acn;
            long double amount;
            cout << "\n\t\t\t******************************************************************";
            cout << "\n\t\t\tEnter your account number: ";
            cin >> acn;
            BankAccount *account = bank.FindAccount(acn);
            if (account != NULL)
            {
                cout << "\n\t\t\tEnter the amount you want to withdraw: ";
                cin >> amount;
                account->withdraw(amount);
                cout << "\n\t\t\t< R.S " << amount << " W I T H D R A W E D   S U C C E S S F U L L Y >";
                cout << "\n\t\t\t<PLEASE RECIEVE YOUR CASH>";
            }
            else
            {
                cout << "\n\t\t\t< A C C O U N T  N O T  F O U N D >";
            }
            cout << "\n\t\t\t******************************************************************";
            break;
        }

        case 6:
            exit(1);
            break;

        default:
            cout << "\n\t\t\tInvalid Choice. Please try again." << endl;
            break;
        }

        cout << "\n\t\t\tDo You Want To Continue [Yes(1)/No(0)]: ";
        cin >> op;
    } while (op == 1);

    return 0;
}
