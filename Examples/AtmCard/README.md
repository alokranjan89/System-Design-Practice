# ATM Card Exercise

A small C++ exercise for modeling PIN authentication and basic account operations through an ATM. It covers balance checks, deposits, withdrawals, transactions, and receipts.

## Main roles

| Class | Responsibility |
|---|---|
| `Account` | Common account data and deposit/withdraw behavior |
| `SavingAccount`, `CurrentAccount` | Concrete account types |
| `AtmCard` | Holds card data and verifies a PIN |
| `Customer` | Connects customer details, card, and account |
| `ATM` | Coordinates authentication and account operations |
| `Transaction`, `Receipt` | Represent transaction details and printed balance |

## Flow

1. Create an account, card, and customer.
2. The ATM verifies the entered PIN.
3. The ATM performs the requested balance check, deposit, or withdrawal.
4. Successful deposits and withdrawals produce transaction details and a receipt.

The model is intentionally small. Treat it as an OOP exercise, not a secure or complete banking system; real authentication, money representation, persistence, and transaction safety require more design.

## Build

From the repository root:

```powershell
g++ -std=c++17 -Wall -Wextra Examples/AtmCard/atm_card.cpp -o atm_card.exe
.\atm_card.exe
```
