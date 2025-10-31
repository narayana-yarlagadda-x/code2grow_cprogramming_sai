#include <stdio.h>

int main() {
int choice;
double balance = 10000.0;
double amount;
do {
printf("Menu:");
printf("1. Deposit Money");
        printf("2. Withdraw Money");
        printf("3. Check Balance");
        printf("4. Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Deposit Money
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                if (amount > 25000) {
                    balance += amount + (amount * 0.01); // 1% bonus
                    printf("Bonus of %.2lf added!", amount * 0.01);
                } else {
                    balance += amount;
                }
                balance -= 5; // Service charge
                printf("Service charge 5 applied.");
                printf("Updated Balance: %.2lf", balance);
                break;

            case 2: // Withdraw Money
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                if (amount > balance) {
                    printf("Withdrawal not allowed, insufficient balance!");
                } else {
                    balance -= amount;
                    balance -= 5; // Service charge
                    printf("Service charge 5 applied.");
                    printf("Updated Balance: %.2lf", balance);
                }
                break;

            case 3: // Check Balance
                printf("Current Balance: %.2lf", balance);
                break;

            case 4: // Exit
                printf("Thank you for banking with us!");
                break;

            default:
                printf("Invalid choice! Please select between 1-4.");
        }
    } while (choice != 4);

    return 0;
}
