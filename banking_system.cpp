#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class BankAccount
{ 
    public:
    string accountHolder;
    float accountnumber = 0;
    float balance = 0;

    // Function to save single account to file (append mode)
    void saveAccountToFile(const string& filename)
    {
        ofstream outFile(filename, ios::app); // ios::app = append mode
        if (outFile.is_open())
        {
            outFile << accountHolder << endl;
            outFile << accountnumber << endl;
            outFile << balance << endl;
            outFile << "---" << endl; // Separator between accounts
            outFile.close();
        }
        else
        {
            cout << "Error: Could not save to file!" << endl;
        }
    }

    // Function to load single account from file
    bool loadAccountFromFile(ifstream& inFile)
    {
        if (getline(inFile, accountHolder))
        {
            inFile >> accountnumber;
            inFile >> balance;
            inFile.ignore(); // Clear newline after reading balance
            string separator;
            getline(inFile, separator); // Read separator line
            return true;
        }
        return false;
    }

    // Display account details
    void display() const
    {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountnumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class BankSystem
{
    private:
    vector<BankAccount> accounts;
    const string filename = "account_data.txt";

    public:
    // Load all accounts from file
    void loadAllAccounts()
    {
        ifstream inFile(filename);
        if (inFile.is_open())
        {
            accounts.clear(); // Clear existing accounts
            BankAccount account;
            while (account.loadAccountFromFile(inFile))
            {
                accounts.push_back(account);
            }
            inFile.close();
            if (accounts.size() > 0)
            {
                cout << "Loaded " << accounts.size() << " account(s) from file: " << filename << endl;
            }
        }
    }

    // Save all accounts to file (overwrite mode)
    void saveAllAccounts()
    {
        ofstream outFile(filename); // Overwrite mode
        if (outFile.is_open())
        {
            for (const auto& account : accounts)
            {
                outFile << account.accountHolder << endl;
                outFile << account.accountnumber << endl;
                outFile << account.balance << endl;
                outFile << "---" << endl;
            }
            outFile.close();
        }
        else
        {
            cout << "Error: Could not save to file!" << endl;
        }
    }

    // Generate unique account number
    float generateAccountNumber()
    {
        float newAccountNumber = 10000; // Starting account number
        
        // Find the highest account number and add 1
        for (const auto& account : accounts)
        {
            if (account.accountnumber >= newAccountNumber)
            {
                newAccountNumber = account.accountnumber + 1;
            }
        }
        
        return newAccountNumber;
    }

    // Find account by account number
    int findAccountByNumber(float accountNumber)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].accountnumber == accountNumber)
            {
                return i;
            }
        }
        return -1; // Not found
    }

    // Create new account
    void createAccount()
    {
        BankAccount newAccount;
        cout << "Enter your name: ";
        getline(cin, newAccount.accountHolder);
        
        // Generate account number automatically
        newAccount.accountnumber = generateAccountNumber();
        cout << "Your account number has been generated: " << newAccount.accountnumber << endl;
        
        cout << "Enter Initial Balance: ";
        cin >> newAccount.balance;
        cin.ignore();
        
        accounts.push_back(newAccount);
        saveAllAccounts();
        cout << "Account created and saved successfully!" << endl;
        cout << "Account Number: " << newAccount.accountnumber << endl;
    }

    // Delete account by account number
    void deleteAccount(float accountNumber)
    {
        int index = findAccountByNumber(accountNumber);
        if (index != -1)
        {
            cout << "\nAccount to be deleted:" << endl;
            accounts[index].display();
            
            char confirm;
            cout << "\nAre you sure you want to delete this account? (y/n): ";
            cin >> confirm;
            cin.ignore();
            
            if (confirm == 'y' || confirm == 'Y')
            {
                accounts.erase(accounts.begin() + index);
                saveAllAccounts();
                cout << "Account deleted successfully!" << endl;
            }
            else
            {
                cout << "Deletion cancelled." << endl;
            }
        }
        else
        {
            cout << "Account not found!" << endl;
        }
    }

    // Display all accounts with delete option
    void displayAllAccounts()
    {
        if (accounts.empty())
        {
            cout << "No accounts found. Please create an account first." << endl;
            return;
        }
        
        cout << "\n-------- All Accounts --------" << endl;
        for (int i = 0; i < accounts.size(); i++)
        {
            cout << "\nAccount #" << (i + 1) << ":" << endl;
            accounts[i].display();
            cout << "----------------------------" << endl;
        }
        
        // Ask if user wants to delete an account
        char choice;
        cout << "\nDo you want to delete an account? (y/n): ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 'y' || choice == 'Y')
        {
            float accountNum;
            cout << "Enter account number to delete: ";
            cin >> accountNum;
            cin.ignore();
            deleteAccount(accountNum);
        }
    }

    // Display single account
    void displayAccount()
    {
        if (accounts.empty())
        {
            cout << "No accounts found. Please create an account first." << endl;
            return;
        }
        
        float accountNum;
        cout << "Enter account number to display: ";
        cin >> accountNum;
        cin.ignore();
        
        int index = findAccountByNumber(accountNum);
        if (index != -1)
        {
            cout << "\n-------- Account Details --------" << endl;
            accounts[index].display();
        }
        else
        {
            cout << "Account not found!" << endl;
        }
    }

    // Deposit money
    void depositMoney()
    {
        if (accounts.empty())
        {
            cout << "No accounts found. Please create an account first." << endl;
            return;
        }
        
        float accountNum;
        cout << "Enter account number: ";
        cin >> accountNum;
        cin.ignore();
        
        int index = findAccountByNumber(accountNum);
        if (index != -1)
        {
            float money;
            cout << "Enter amount to deposit: ";
            cin >> money;
            cin.ignore();
            
            if (money > 0)
            {
                accounts[index].balance += money;
                saveAllAccounts();
                cout << "Deposit successful! New balance: " << accounts[index].balance << endl;
            }
            else
            {
                cout << "Invalid amount!" << endl;
            }
        }
        else
        {
            cout << "Account not found!" << endl;
        }
    }

    // Withdraw money
    void withdrawMoney()
    {
        if (accounts.empty())
        {
            cout << "No accounts found. Please create an account first." << endl;
            return;
        }
        
        float accountNum;
        cout << "Enter account number: ";
        cin >> accountNum;
        cin.ignore();
        
        int index = findAccountByNumber(accountNum);
        if (index != -1)
        {
            float amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            cin.ignore();
            
            if (amount <= 0)
            {
                cout << "Invalid amount!" << endl;
            }
            else if (accounts[index].balance < amount)
            {
                cout << "Insufficient balance!" << endl;
            }
            else
            {
                accounts[index].balance -= amount;
                saveAllAccounts();
                cout << "Withdrawal successful! New balance: " << accounts[index].balance << endl;
            }
        }
        else
        {
            cout << "Account not found!" << endl;
        }
    }

};

 
int main()
{
    int choice;
    BankSystem bank;
    
    // Load all accounts from file when program starts
    bank.loadAllAccounts();
    
    do
    {
        cout << "\n------ Banking Menu ------\n";
        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Display Single Account\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline from buffer after reading choice
        
        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;

        case 2:
            bank.displayAllAccounts();
            break;
        
        case 3:
            bank.displayAccount();
            break;
        
        case 4:
            bank.depositMoney();
            break;
        
        case 5:
            bank.withdrawMoney();
            break;
            
        case 6:
            bank.saveAllAccounts();
            cout << "Exiting. Thank you!" << endl;
            break;
            
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }

    } while (choice != 6);
    
    cout << endl;
    return 0;
}