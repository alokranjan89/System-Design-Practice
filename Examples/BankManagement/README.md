# Bank Management

This example demonstrates a simple bank model using object-oriented design.

## Key Concepts

- Inheritance with `Account`, `SavingsAccount`, and `CurrentAccount`
- Composition: `Customer` owns `Account` objects
- Aggregation: `Bank` stores customers
- Resource cleanup using destructors

## Main Classes

| Class | Responsibility |
|---|---|
| `Account` | Base account with balance, deposit, withdraw, and balance display |
| `SavingsAccount` | Concrete savings account type |
| `CurrentAccount` | Concrete current account type |
| `Customer` | Owns one or more accounts |
| `Bank` | Stores customers and displays their accounts |

## How To Run

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\Examples\BankManagement"
g++ -std=c++17 -Wall -Wextra bank_management.cpp -o bank_management.exe
./bank_management.exe
```
