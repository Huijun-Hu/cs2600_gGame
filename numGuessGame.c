#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* 
Number Guessing Game
@ author : Huijun Hu
 - dispaly game menu to user. 
 - 1 : start game
 - 2 : change max limit 
 - 3 : quit
*/

void play(int m){

    /* variables declarations */
    int guess, target;
    char input[5];
    time_t t;

    /* initialize random number generator and generate a number */
	srand((unsigned)time(&t));
	target = rand() % (m+1);
    // printf("%d", target);
    printf("\nEnter a number for 0 to %d (q to quit): ", m);
    scanf("%s", input);
    
    /* exit util q or won */
    do{
        guess = atoi(input);
        if (strcmp(input, "q") == 0){
            break;
        }
        else if (guess == target){
            printf("Bingo!!\n");
            break;
        }
        else if (guess < target){
            printf("Your guess is too low, try again: ");
            scanf("%s", input);
        }
        else if (guess > target){
            printf("Your guess is too high, try again: ");
            scanf("%s", input);
        }
    } while (!(strcmp(input, "q") == 0) || !(guess == target));  
    
} /* end play */

int changeMax(){

    int result;
    printf("You would like to change to Maximum Number to (100 limit) : ");
    scanf("%d", &result);

    /* check validity of new maxNum */
    while (result < 0){
        printf("Warning: Maximum cannot be negative.\nEnter again: ");
        scanf("%d", &result);
    }
    while (result > 100){
        printf("Warning: Maximum cannot exceed 100.\nEnter again: ");
        scanf("%d", &result);
    }

    return result;
} /* changeMax */

void quit(){
    printf("\nThank you for playing.\n");
    exit(0);
} /* end quit */

int main(){

    /* default user option prevent exit program */
    int user_option = -1;
    /* default max number */
    int maxNum = 10;
    
    do{
        printf("\n---Welcome to Number Guessing Game---\nPress 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n");
        scanf("%d", &user_option);

        switch(user_option) {
            case 1  :
                play(maxNum);
                break;
	        case 2  :
                maxNum = changeMax();
                printf("Maximum Number now set to %d\n", maxNum);
                break;
            case 3  :
                quit();
        } /* end switch */
    }while(!(user_option == 3));
    
    return 0;
} /* end main */


