#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BankAccount
{ 
    public:
    string accountHolder;
    int accountnumber = 0;
    int balance = 0;

    void createaccount()
    {
        cout<<"Enter your name :- ";
        cin.ignore();
        getline(cin, accountHolder);
        cout<<"Enter your account number :- ";
        cin.ignore();
        cin>>accountnumber;
        cout<<"Enter Intial Balance :- ";
        cin.ignore();
        cin>>balance;

    }

    void Displayaccount()
    {
        if (accountHolder == "" && accountnumber > 0)
        {
            cout<<"--------Account Details--------"<<endl;
            cout<<"Account Holder :- "<<accountHolder<<endl;
            cout<<"Account Number :- "<<accountnumber<<endl;
            cout<<"Balance :- "<<balance<<endl;
        }
        else
        {
            cout<<"First create account"<<endl;
        }
        
        
    }

    void Addmoney()
    {
        int money;
        cout<<"Enter Amount :- ";
        cin.ignore();
        cin>>money;
        balance += money;
        cout<<endl;
        cout<<"Your Current Balance :- "<<balance;
    }

    void WithDrawMoney()
    {
        int amount;
        cout<<"Enter the Amount that you what to Withdraw :-  ";
        cin>>amount;
        if (balance < amount)
        {
            cout<<"Insufficient balance"<<endl;
        }
        else
        {
            balance -= amount;
            cout<<endl;
            cout<<"Your Current Balance :- "<<balance;
        }
        
        
    }

};

 
int main()
{
    int choice;
    BankAccount account;
    do
    {
        cout << "\n------ Banking Menu ------\n";
    cout << "1. Create Account\n";
    cout << "2. Display All Accounts\n";
    cout << "3. Deposit Money\n";
    cout << "4. Withdraw Money\n";
    cout << "5. Exit\n";
    cout << "Enter your choice:- ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        account.createaccount();
        break;

    case 2:
        account.Displayaccount();
        break;
    
    case 3:
        account.Addmoney();
        break;
    
    case 4:
        account.WithDrawMoney();
        break;
        
    case 5:
       cout<<"Exiting. Thank you!"<<endl;
       break;
    default:
        cout<<"Invalid choice"<<endl;
        break;
    }

    } while (choice != 5);
    

    cout<<endl;
}