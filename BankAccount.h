//
// Created by CSStudent on 9/15/2026.
//

#ifndef UNTITLED_BANKACCOUNT_H
#define UNTITLED_BANKACCOUNT_H

#include <iostream>
#include <vector>

class BankAccount {
public:
    BankAccount();
    BankAccount(const BankAccount&);

    virtual ~BankAccount();

    BankAccount& operator=(const BankAccount&);
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);

    bool operator==(const BankAccount& other);
    bool operator<(const BankAccount& other);
    bool operator>(const BankAccount& other);

    std::string getAccountNumber();
    std::string getAccountHolderName();
    double getBalance();

    void setAccountHolderName(const std::string &);

    void deposit(double);
    double withdraw(double);
    void void_withdraw(double amount);

    void add_transaction(std::string, double);
    void print_transaction_history();

    virtual void print_details() const;
    static BankAccount* createAccountFromInput();

    std::string acc_type;
    static int NEXT_ID;

    struct Transaction {
        double amount;
        std::string type, timestamp;
    };
protected:
    std::string acc_num, acc_holder_name;
    double balance;

    void setAccountNumber(const std::string&);
    void setBalance(double);

private:
    std::vector<Transaction> transaction_history;
};


class CheckingAccount : public BankAccount {
public:
    CheckingAccount();

    double getTransactionFee();
    void setTransactionFee(double);

    double withdraw(double);
    void void_withdraw(double amount);

    static CheckingAccount* createCheckingAccountFromInput();
    void print_details() const override;
private:
    double transaction_fee;
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount();

    void calculateInterest();

    double getInterest();
    void setInterest(double);

    static SavingsAccount* createSavingsAccountFromInput();
    void print_details() const override;
private:
    double interest_rate;
};

#endif //UNTITLED_BANKACCOUNT_H
