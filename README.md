# 🏦 Banking System with File Storage (C++)

This is a console-based **Banking Management System** implemented in **C++**.  
It supports multiple accounts, persistent file storage, auto-generated account numbers, and basic banking operations.

---

## 📌 Features

✔ Create multiple bank accounts  
✔ Auto-generate unique account number  
✔ Store account data permanently in file  
✔ View all accounts  
✔ View single account using account number  
✔ Deposit & Withdraw money  
✔ Delete accounts safely  
✔ Uses `vector` for dynamic storage  
✔ Graceful invalid input handling  

---

## 🛠 Technologies Used

- **Programming Language:** C++
- **Concepts Used:**
  - Object Oriented Programming (OOP)
  - File Handling (`ifstream`, `ofstream`)
  - Vectors (`std::vector`)
  - `getline()` for string input
  - Persistent storage using `.txt` file

---

- `main.cpp` → Source code  
- `account_data.txt` → Stores account details  
- `README.md` → Project Documentation  

---

## 🗄️ Data Storage Format

Data is stored as:


Each `---` separates two accounts.

---

## ▶️ How to Run

### **Compile using g++**
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

## 📁 File Structure

