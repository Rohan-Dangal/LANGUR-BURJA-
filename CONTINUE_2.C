#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char diceFaces[6][10] = {"chidi", "bhote", "etta", "pana", "jhandi", "burja"};
    char result[6][10];
    char choice[10];
    int age, deposit, bet;
    
    printf("Enter your age: ");
    scanf("%d", &age);
    
    if (age < 18) {
        printf("You are not eligible to play.\n");
        return 0;
    }
    
    printf("Enter deposit amount: ");
    scanf("%d", &deposit);
    
    printf("Choose one (chidi, bhote, etta, pana, jhandi, burja): ");
    scanf("%s", choice);
    
    printf("Enter bet amount: ");
    scanf("%d", &bet);
    
    if (bet > deposit) {
        printf("Not enough balance.\n");
        return 0;
    }
    
    srand(time(NULL));
    for (int i = 0; i < 6; i++) {
        int r = rand() % 6;
        strcpy(result[i], diceFaces[r]);
        printf("%s ", result[i]);
    }
    printf("\n");
    
    int count = 0;
    for (int i = 0; i < 6; i++) {
        if (strcmp(result[i], choice) == 0) {
            count++;
        }
    }
    
    if (count > 0) {
        int win = bet * count;
        deposit += win;
        printf("You won RS%d!\n", win);
    } else {
        deposit -= bet;
        printf("You lost RS%d.\n", bet);
    }
    
    printf("Your balance is RS%d.\n", deposit);
    
    return 0;
}
