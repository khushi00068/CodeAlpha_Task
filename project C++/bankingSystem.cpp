#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 100;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    BankAccount() {
        accountHolderName = "";
        accountNumber = 0;
        balance = 0.0;
    }

    void createAccount() {
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, accountHolderName);
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Initial Balance: Rs. ";
        cin >> balance;
        cout << "Account Created Successfully!\n";
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void showAccount() {
        cout << "\n--- Account Details ---\n";
        cout << "Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    void depositMoney() {
        double amount;
        cout << "Enter amount to deposit: Rs. ";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "Rs. " << amount << " deposited successfully!\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void withdrawMoney() {
        double amount;
        cout << "Enter amount to withdraw: Rs. ";
        cin >> amount;
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Rs. " << amount << " withdrawn successfully!\n";
        } else {
            cout << "Invalid amount or insufficient balance!\n";
        }
    }
};

int findAccount(BankAccount accounts[], int totalAccounts, int accNo) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].getAccountNumber() == accNo) {
            return i;
        }
    }
    return -1;
}

int main() {
    BankAccount accounts[MAX_ACCOUNTS];
    int totalAccounts = 0;
    int choice;
    cout<<"\nWelcome to CODEALPHA banking system\n";

    do {
        cout << "\n===== Banking Management System Includes =====\n";
        cout << "1. Create New Account\n";
        cout << "2. Show Account Details\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == 1) {
            if (totalAccounts >= MAX_ACCOUNTS) {
                cout << "Maximum account limit reached!\n";
                continue;
            }

            int accNo;
            cout << "Enter desired Account Number: ";
            cin >> accNo;

            if (findAccount(accounts, totalAccounts, accNo) != -1) {
                cout << "Account with this number already exists!\n";
                continue;
            }

            accounts[totalAccounts].createAccount();
            totalAccounts++;
        }
        else if (choice == 2) {
            int accNo;
            cout << "Enter Account Number to view details: ";
            cin >> accNo;

            int index = findAccount(accounts, totalAccounts, accNo);
            if (index != -1) {
                accounts[index].showAccount();
            } else {
                cout << "Account not found!\n";
            }
        }
        else if (choice == 3) {
            int accNo;
            cout << "Enter Account Number to deposit: ";
            cin >> accNo;

            int index = findAccount(accounts, totalAccounts, accNo);
            if (index != -1) {
                accounts[index].depositMoney();
            } else {
                cout << "Account not found!\n";
            }
        }
        else if (choice == 4) {
            int accNo;
            cout << "Enter Account Number to withdraw: ";
            cin >> accNo;

            int index = findAccount(accounts, totalAccounts, accNo);
            if (index != -1) {
                accounts[index].withdrawMoney();
            } else {
                cout << "Account not found!\n";
            }
        }
        else if (choice == 5) {
            cout << "Thank you for using our banking system!\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
