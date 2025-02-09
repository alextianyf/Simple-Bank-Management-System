/*
 * =====================================================
 * File: main.c
 * Author: Alex Tian
 * Date: August, 2020
 * Description:
 *     This program simulates a simple banking system where users 
 *     can check their balance, deposit money, withdraw money, 
 *     and exit the system.
 *
 * Features:
 *     - Initial balance starts at $1000.00
 *     - Users can select from four operations:
 *         1. Check balance
 *         2. Deposit money
 *         3. Withdraw money
 *         4. Exit the system
 *     - The system handles invalid inputs gracefully.
 *     - Ensures deposit and withdrawal amounts are valid.
 *
 * Usage:
 *     - Compile with: gcc main.c -o simple_bank
 *     - Run the program: ./simple_bank
 * =====================================================
 */

#include <stdio.h>
#include <stdbool.h>

int main() {
    // Constant Definitions
    const float INITIAL_BALANCE = 1000.0; // Initial Balance
    const int QUERY_BALANCE = 1;
    const int DEPOSIT = 2;
    const int WITHDRAW = 3;
    const int EXIT = 4;

    // Account Status Variables
    float balance = INITIAL_BALANCE;
    int choice;
    float amount;
    bool running = true;

    // Welcome Screen
    printf("====================================\n");
    printf("      Welcome to the Simple Bank      \n");
    printf("====================================\n");
    printf("Your initial balance is: %.2f USD\n\n", balance);

    while (running) {
        // Display Operation Menu
        printf("Please select an operation:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");

        // Check if valid input was entered
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number between 1 and 4.\n\n");
        }

        // Handle User Choice
        else if (choice == QUERY_BALANCE) {
            printf("\nYour current balance is: %.2f USD\n\n", balance);
        }
        else if (choice == DEPOSIT) {
            printf("\nEnter deposit amount: ");
            scanf("%f", &amount);

            if (amount > 0) {
                balance += amount;
                printf("Deposit successful!\n");
                printf("Your new balance is: %.2f USD\n\n", balance);
            } else {
                printf("Deposit amount must be greater than 0!\n\n");
            }
        }
        else if (choice == WITHDRAW) {
            printf("\nEnter withdrawal amount: ");
            scanf("%f", &amount);

            if (amount > 0) {
                if (amount <= balance) {
                    balance -= amount;
                    printf("Withdrawal successful!\n");
                    printf("Your new balance is: %.2f USD\n\n", balance);
                } else {
                    printf("Insufficient balance. Withdrawal failed.\n\n");
                }
            } else {
                printf("Withdrawal amount must be greater than 0!\n\n");
            }
        }
        else if (choice == EXIT) {
            printf("\nThank you for using the Simple Bank System. Goodbye!\n");
            running = false;
        } else {
            printf("\nInvalid choice. Please enter a number between 1 and 4.\n\n");
        }

        // Clear input buffer to avoid infinite loop in case of invalid input
        while (getchar() != '\n');
    }

    return 0;
}