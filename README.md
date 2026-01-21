# 🏦 Banking System (C++) — Final Version

A complete console-based **Banking Management System** written in **C++** with file storage, multiple accounts support, auto-generated account numbers, and basic transaction handling.

---

## 🔹 Key Features

- Create multiple bank accounts
- Auto-generate unique account numbers
- Store account data permanently in a `.txt` file
- Display all stored accounts
- Display a single account using account number
- Deposit & withdraw money
- Delete specific accounts
- Prevent negative transactions & invalid access
- Uses `vector` for dynamic storage
- Data persistence using file I/O

---

## 🧰 Technologies & Concepts Used

| Category | Details |
|---------|---------|
| Language | C++ |
| Concepts | OOP (Classes), File Handling, Vectors, Input Validation |
| Files | `ifstream`, `ofstream`, `.txt` file |
| Storage | Persistent (non-volatile) |

---

## 📁 Project Structure

BankingSystem/
├── main.cpp
├── account_data.txt ← auto-created at runtime
└── README.md

---

## 🗄️ Data Storage Format (`account_data.txt`)


Each `---` represents a separator between two accounts.

---

## ▶️ How to Compile & Run

### **Using g++**
```sh
g++ main.cpp -o bank
./bank
------ Banking Menu ------
1. Create Account
2. Display All Accounts
3. Display Single Account
4. Deposit Money
5. Withdraw Money
6. Exit
Enter your choice:
📝 Example Usage
Creating Account
Enter your name: Harry Potter
Your account number has been generated: 10001
Enter Initial Balance: 5000
Account created and saved successfully!

Deposit
Enter account number: 10001
Enter amount to deposit: 1500
Deposit successful! New balance: 6500

Withdraw
Enter account number: 10001
Enter amount to withdraw: 2000
Withdrawal successful! New balance: 4500

Delete
Enter account number to delete: 10001
Account deleted successfully!
