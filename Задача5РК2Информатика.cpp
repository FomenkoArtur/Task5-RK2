#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string number;
    string name;
    double balance;

public:
    BankAccount(string num, string owner, double bal): number(num), name(owner), balance(bal) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Пополнено: " << amount << ". Текущий баланс: " << balance << endl;
        }
        else {
            cout << "Сумма пополнения должна быть положительной." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снято: " << amount << ". Текущий баланс: " << balance << endl;
        }
        else {
            cout << "Недостаточно средств для снятия." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void displayAccountInfo() const {
        cout << "Номер счёта: " << number << ", Владельцы: " << name << ", Баланс: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double rate;
public:
    SavingsAccount(string num, string owner, double balance, double rate): BankAccount(num, owner, balance), rate(rate) {}

    void app() {
        double interest = getBalance() * (rate / 100);
        deposit(interest);
        cout << "Начислены проценты: " << interest << ". Текущий баланс: " << getBalance() << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    BankAccount acc("123456789", "Иван Иванов", 1000.0);
    acc.displayAccountInfo();

    acc.deposit(500.0);
    acc.withdraw(200.0);
    acc.withdraw(1500.0);

    SavingsAccount sacc("987654321", "Петр Петров", 2000.0, 5.0);
    sacc.displayAccountInfo();

    sacc.deposit(300.0);
    sacc.withdraw(100.0);
    sacc.app();

    return 0;
}
