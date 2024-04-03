// PRCT_5_C++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <Windows.h>
#include <iostream>
using namespace std;



class BankAccount {
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accountNumber, double balance) {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->interestRate = 0;
    }

    void deposit(double cash) {
        this->balance += cash;
    }
    void withdrow(double cash) {
        if (this->balance - cash > 0)
            this->balance -= cash;
        else {
            cout << "Недостаточно средств";
        }
    }
    double getBalance() {
        return balance;
    }
    double getInterest() {
        return balance * interestRate * (double)(1.0 / 12.0);
    }
    void setInterestRate(double newRate) {
        this->interestRate = newRate;
    }
    int getAccountNumber() {
        return accountNumber;
    }

    friend void trancfer(BankAccount& acc1, BankAccount& acc2, double cash) {
        if (acc1.getBalance() - cash > 0) {
            acc2.deposit(cash);
            acc1.withdrow(cash);
        }
        else {
            cout << "Недостаточно средств";
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    setlocale(0, "ru");
    int s;
    do {
        int num;
        double balance;
        cout << "Введите номер первого аккаунта\n";
        cin >> num;
        cout << "Введите баланс первого аккаунта\n";
        cin >> balance;
        BankAccount acc1(num, balance);
        cout << "Введите номер второго аккаунта\n";
        cin >> num;
        cout << "Введите баланс второго аккаунта\n";
        cin >> balance;
        BankAccount acc2(num, balance);

        double b;
        double result;
        int n;
        do {
            cout << "Что вы хотите сделать?\n1. Внести деньги\n2. Вывести деньги\n3. Получить баланс\n4. Получить процнт\n5. Изменить процентную ставку\n6. Узнать номер аккаунта\n7. Перевести деньги на другой аккаунт\n";
            cin >> s;
            switch (s)
            {
                case(1):
                    cin >> b;
                    acc1.deposit(b);
                    break;
                case(2):
                    cin >> b;
                    acc1.withdrow(b);
                    break;
                case(3):
                    cout << acc1.getBalance() << "\n";
                    break;
                case(4):
                    cout << acc1.getInterest() << "\n";
                    break;
                case(5):
                    cin >> b;
                    acc1.setInterestRate(b);
                    break;
                case(6):
                    cout << acc1.getAccountNumber() << "\n";
                    break;
                case(7):
                    cout << "Введите номер аккаунта на который хотите перевести деньги\n";
                    cin >> n;
                    if (n == acc2.getAccountNumber()) {
                        cout << "Сколько хотите перевести?\n";
                        cin >> b;
                        trancfer(acc1, acc2, b);
                        break;
                    }
                    else {
                        cout << "Такого аккаунта нет!\n";
                        break;
                    }
                    break;
                case(8):
                    cout << "Пока!";
                    break;
            }
        } while (s != 8);
    } while (s!=8);
}

