#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_SIDES 6

// Function to display the rules of the game
void displayRules() {
    printf("\nRULES FOR THE DICE GAME:\n");
    printf("1. You must be 18 or older to play.\n");
    printf("2. Choose one of the following options: chidi, bhote, etta, pana, jhandi, burja.\n");
    printf("3. The computer will roll a dice with these 6 faces.\n");
    printf("4. If your choice appears on the dice, you win money based on how many times it appears.\n");
    printf("5. For each occurrence of your choice on the dice, you win your bet amount multiplied by that number of occurrences.\n");
}

// Function to roll the dice and fill the result array
void rollDice(char diceFaces[NUM_SIDES][10], char result[NUM_SIDES][10]) {
    for (int i = 0; i < NUM_SIDES; i++) {
        int randomIndex = rand() % NUM_SIDES;
        strcpy(result[i], diceFaces[randomIndex]);
    }
}

// Function to play the game
void playGame() {
    char diceFaces[NUM_SIDES][10] = {"chidi", "bhote", "etta", "pana", "jhandi", "burja"};
    char result[NUM_SIDES][10];
    char choice[10];
    int age, deposit, bet;
    
    printf("Enter your name: ");
    char name[50];
    scanf("%s", name);
    printf("\n");

    printf("Enter your age: ");
    scanf("%d", &age);
    
    if (age < 18) {
        printf("Sorry, you are not eligible to play the game. Have a good day!\n");
        return;
    }

    printf("You are eligible to play this game.\n");

    printf("Enter the money you want to deposit: ");
    scanf("%d", &deposit);
    printf("\n");

    printf("Your current balance is RS%d\n", deposit);

    printf("Choose one of the following: chidi, bhote, etta, pana, jhandi, burja\n");
    scanf("%s", choice);

    // Validate choice
    int validChoice = 0;
    for (int i = 0; i < NUM_SIDES; i++) {
        if (strcmp(choice, diceFaces[i]) == 0) {
            validChoice = 1;
            break;
        }
    }
    
    if (!validChoice) {
        printf("Invalid choice. Please restart the game and choose a valid option.\n");
        return;
    }

    printf("%s, enter the money to bet: RS", name);
    scanf("%d", &bet);
    
    while (bet > deposit) {
        printf("Insufficient balance. Enter again: RS");
        scanf("%d", &bet);
    }
    
    srand(time(NULL));
    rollDice(diceFaces, result);

    int matchCount = 0;
    for (int i = 0; i < NUM_SIDES; i++) {
        if (strcmp(result[i], choice) == 0) {
            matchCount++;
        }
    }

    printf("\nDice roll results:\n");
    for (int i = 0; i < NUM_SIDES; i++) {
        printf("%s ", result[i]);
    }
    printf("\n");

    if (matchCount > 0) {
        int winnings = bet * matchCount;
        printf("Your choice '%s' appeared %d time(s).\n", choice, matchCount);
        printf("You have won RS%d\n", winnings);
        deposit += winnings - bet; // Update balance: add winnings and subtract the bet
    } else {
        printf("Your choice did not appear at all. You have lost RS%d\n", bet);
        deposit -= bet; // Update balance: subtract the bet
    }
    
    printf("Now you have RS%d as balance\n", deposit);
    
    if (deposit <= 0) {
        printf("Sorry, you have no money left. Have a nice day!\n");
    }
}

int main() {
    displayRules();
    printf("\n");
    playGame();
    return 0;
}
