// START:
// - Starts with a balance of 4,577 and PIN "9999".

// 1. LOGIN:
// - User has 3 tries to enter the correct PIN.
// - Success opens the menu; failure exits the program.

// 2. MAIN MENU:
// - Shows 4 options: Check Balance, Withdraw, Deposit, Exit.
// - If the user types letters instead of numbers, it clears the input and asks again.

// 3. ACTIONS:
// - Check Balance: Asks for PIN again, then shows the balance.
// - Deposit: Asks for an amount (>0) and PIN, then adds it to the balance.
// - Withdraw: Asks for an amount (>0 and <= balance) and PIN, then subtracts it from the balance.

// 4. EXIT:
// - Option 4 prints an exit message and stops the program.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int balance = 4577;

const char correct_pin[5] = "9999";

void clear_buffer(void) {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

bool login() {
    char pin[50];
    int count = 2;
    while (count <= 2 && count >= 0) {
        printf("Enter PIN: ");
        if(scanf(" %s", pin) == 1 && strcmp(correct_pin, pin) == 0) {
            printf("Correct PIN.\n");
            printf("Successful login.\n");
            return true;
        } else {
            printf("Wrong PIN.\n");
            if (count >= 1) {
                printf("Try again. Attempts remaining %d\n", count--);
                    continue;
            } else {
                printf("No attempts remaining.\n\tExiting System.\n");
                    return false;
            }
        }
    }
}

void checkBalance() {
    char pin[50];
    printf("Enter PIN: \n");

    if (scanf(" %s", pin) == 1 && strcmp(correct_pin, pin) == 0) {
        printf("Dear customer, your account balance is %d.\n", balance);
    } else {
        printf("You have entered the wrong PIN.\n");
    }
}



void display_menu(void) {
    printf("\n1. Balance Inquiry.\n");
    printf("2. Withdraw.\n");
    printf("3. Deposit.\n");
    printf("4. Exit.\n");

    printf("Choose an option above.\n");
}

void deposit(int amount) {
    char pin[50];
    if (amount < 1) {
        printf("Invalid amount.\n");
    } else {
        printf("\nEnter PIN to confirm deposit of %d: \n", amount);
        if (scanf(" %s", pin) == 1 && strcmp(correct_pin, pin) == 0) {
            balance += amount;
            printf("You have successfully deposited %d in your account.\n", amount);
            return;
        } else {
            printf("You have entered the wrong PIN.\n");
            return;
        }
    }
}

void withdraw(int amount) {
    char pin[50];
    if (amount < 1) {
        printf("Invalid amount.\n");
    } else {
        if (amount > balance) {
            printf("You have insufficient funds.\n");
            return;
        }
        printf("\nEnter PIN to confirm withdrawal of %d: \n", amount);
        if (scanf(" %s", pin) == 1 && strcmp(correct_pin, pin) == 0) {
            balance -= amount;
            printf("You have successfully withdrawn %d in your account.\n", amount);
            return;
        } else {
            printf("You have entered the wrong PIN.\n");
            return;
        }
    }
}

int main()
{
    if (login() == true) {
        bool running = true;
        int amount;
        while (running) {
            int choice;
            display_menu();
            if (scanf("%d", &choice) != 1) {
                printf("That option contain letters or symbols. Try again.\n");
                clear_buffer();
                continue;
            }

            switch (choice) {
                case 1 : checkBalance();
                         break;
                case 2 : printf("Enter amount you would like to withdraw: ");
                         if (scanf("%d", &amount) == 1) {
                            withdraw(amount);
                         } else {
                            printf("Invalid amount.\n");
                            clear_buffer();
                         }
                         break;
                case 3 : printf("Enter amount you would like to deposit: ");
                         if (scanf("%d", &amount) == 1) {
                            deposit(amount);
                         } else {
                            printf("Invalid amount.\n");
                            clear_buffer();
                         }
                         break;
                case 4 : printf("Exiting system.\n");
                         running = false;
                         return 0;
                default : printf("\nInvalid option. Please try again.\n");
                          clear_buffer();
                          break;
            }

        }
    }
    return 0;

}
