#include <stdio.h>
#include <string.h>

float balance = 50.0;

void display_balance() {
    printf("------------------------------\nyour current balance is %0.2f euro\n------------------------------\n", balance);
}
void deposit(float amount) {
    balance += amount;
    printf("deposited %0.2f euro\n", amount);
    display_balance();
}
void withdraw(float amount) {
    if (balance >= amount) {
        balance -= amount;
        printf("%0.2f withdrawn\n", amount);
        display_balance();
    }
    else {
        printf("you do not have the required funds\n");
    }
}

void main() {
    char command[20] = "beginning value";
    char temp[20] = "urmom";
    float amount = 0;
    int while_val = 1;
    do {
        printf("welcome to your bank.\nwhat would you like to do?\n(display, deposit, withdraw, cancel)\n");
        scanf_s("%s", command, 20);
        if (!strcmp(command, "display")) {
            display_balance();
        }
        else if (!strcmp(command, "deposit")) {
            printf("how much would you like to deposit?\n");
            scanf_s("%f", &amount);
            deposit(amount);
        }
        else if (!strcmp(command, "withdraw")) {
            printf("how much would you like to withdraw?\n");
            scanf_s("%f", &amount);
            withdraw(amount);
        }
        else if (!strcmp(command, "cancel")) {
            while_val = 0;
            break;
        }
    } while (while_val);
}
