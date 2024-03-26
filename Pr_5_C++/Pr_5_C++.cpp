#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <Windows.h>
using namespace std;

int main() {
    int accNum1, accNum2;
    double initialBal1, initialBal2, depositAmount, withdrawAmount, interestRate, transferAmount;

    cout << "Введите номер счета для счета 1: ";
    cin >> accNum1;
    cout << "Введите начальный баланс для счета 1: ";
    cin >> initialBal1;

    BankAccount account1(accNum1, initialBal1);

    cout << "Введите номер счета для счета 2: ";
    cin >> accNum2;
    cout << "Введите начальный баланс для счета 2: ";
    cin >> initialBal2;

    BankAccount account2(accNum2, initialBal2);

    cout << "Введите сумму для внесения на счет 1: ";
    cin >> depositAmount;
    account1.deposit(depositAmount);

    cout << "Введите сумму для вывода со счета 1: ";
    cin >> withdrawAmount;
    account1.withdraw(withdrawAmount);

    cout << "Введите процентную ставку для счета 1: ";
    cin >> interestRate;
    account1.setInterestRate(interestRate);

    cout << "Проценты, полученные на счете " << account1.getAccountNumber() << ": " << account1.getInterest() << endl;

    cout << "Введите сумму для перевода со счета 1 на счет 2: ";
    cin >> transferAmount;
    transfer(account1, account2, transferAmount);

    return 0;
}

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNumber, double initialBalance) {
        this->accountNumber = accNumber;
        this->balance = initialBalance;
        this->interestRate = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            this->balance += amount;
            cout << "Депозит успешен. Новый баланс: " << this->balance << endl;
        }
        else {
            cout << "Неверная сумма депозита." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= this->balance) {
            this->balance -= amount;
            cout << "Вывод успешен. Новый баланс: " << this->balance << endl;
        }
        else {
            cout << "Неверная сумма вывода или недостаточно средств." << endl;
        }
    }

    double getBalance() {
        return this->balance;
    }

    double getInterest() {
        return this->balance * this->interestRate * (1.0 / 12);
    }

    void setInterestRate(double newRate) {
        this->interestRate = newRate;
    }
    
    int getAccountNumber() {
        return this->accountNumber;
    }

    friend bool transfer(BankAccount& fromAccount, BankAccount& toAccount, double amount) {
        if (amount > 0 && amount <= fromAccount.balance) {
            fromAccount.balance -= amount;
            toAccount.balance += amount;
            cout << "Перенос успешен. Новый баланс на счете " << fromAccount.accountNumber << ": " << fromAccount.balance << endl;
            cout << "Новый баланс на счете " << toAccount.accountNumber << ": " << toAccount.balance << endl;
            return true;
        }
        else {
            cout << "Перенос не удался. Неверная сумма или недостаточно средств на счету " << fromAccount.accountNumber << endl;
            return false;
        }
    }
};

