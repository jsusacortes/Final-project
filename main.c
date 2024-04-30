#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 100
#define FILENAME "accounts.txt"

typedef struct {
    int account_number;
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void createAccount() {
    if (num_accounts < MAX_ACCOUNTS) {
        printf("Enter account number: ");
        scanf("%d", &accounts[num_accounts].account_number);
        accounts[num_accounts].balance = 0.0;
        num_accounts++;
        printf("Account created successfully!\n");
    } else {
        printf("Maximum number of accounts reached.\n");
    }
}

void deposit() {
    int acc_num;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == acc_num) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    int acc_num;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == acc_num) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient funds.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void checkBalance() {
    int acc_num;
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == acc_num) {
            printf("Account balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void saveAccountsToFile() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    for (int i = 0; i < num_accounts; i++) {
        fprintf(file, "%d %.2f\n", accounts[i].account_number, accounts[i].balance);
    }
    fclose(file);
    printf("Accounts saved to file successfully.\n");
}

int main() {
    char choice;
    do {
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Save Accounts to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                createAccount();
                break;
            case '2':
                deposit();
                break;
            case '3':
                withdraw();
                break;
            case '4':
                checkBalance();
                break;
            case '5':
                saveAccountsToFile();
                break;
            case '6':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 6.\n");
        }
    } while (choice != '6');

    return 0;
}
