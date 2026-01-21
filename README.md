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


Follow these steps to run the project depending on your setup:

### **🔸 Option 1: Using g++ (Terminal / CMD / PowerShell)**

1. Open terminal in project folder
2. Compile the code:
   ```sh
   g++ main.cpp -o bank
   Run the executable:

./bank

On Windows use:

bank.exe


------ Banking Menu ------
1. Create Account
2. Display All Accounts
3. Display Single Account
4. Deposit Money
5. Withdraw Money
6. Exit
Enter your choice:


