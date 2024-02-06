#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main(){
    // storing words
    char wordlist[][10] = {"apple","chair","brain","bread","brush","chest","chord","dance","click","cloud"};
    int totalWords = sizeof(wordlist) / sizeof(wordlist[0]);
    // welcome message
    printf("--------------------------------------\n");
    printf("  Welcome to the 5 words hangman\n");
    printf("     Guess the 5 letter word\n");
    printf("--------------------------------------\n");
    printf("You get 10 points for each guess left!\n");
    int userHealth = 5;
    printf("Guess left :%d\n",userHealth);
    printf("--------------------------------------\n");


    // choosing a random world from the array
    srand(time(NULL));
    int randomNumber;
    randomNumber = rand() % (totalWords - 1);
    char word[10];
    strcpy(word,wordlist[randomNumber]);

    bool correct;
    char guessed[] = "-----";
    while(userHealth > 0){
        
        if(!strchr(guessed,'-')){
            int points = userHealth * 10;
            printf("\n-----------------------------------------------");
            printf("\nCongratulations! Word is correctly guessed!\n");
            printf("The word was %s.\n",word);
            printf("You got %d points.\n",points);
            printf("Thank you for playing.\n");
            printf("-----------------------------------------------");
            break;
        }
        if(correct){
            correct = false;
            char guess = 'm';
            scanf("%c", &guess);
            continue;
        };
        char guess = 'm';
        printf("\nPlease guess a letter:");
        scanf("%c", &guess);
        if(strchr(word,guess)){
            if(strchr(guessed,guess)){
                printf("-----------------------------");
                printf("\nYou have already guessed this letter!\n");
                printf("Try another letter!\n");
                printf("Word : %s\n",guessed);
                printf("-----------------------------");
                correct = true;
                continue;
            }
            printf("-----------------------------");
            printf("\nNice!The guess was correct!\n");
            int numbers[4];
            int numberIndex = 0;
            int i;
            for(i = 0;i <= 5;i++){
                if(word[i] == guess){
                    numbers[numberIndex] = i;
                    numberIndex++;
                }
            } 
            for(i = 0 ; i < numberIndex ; i++){
                int index = numbers[i];
                guessed[index] = guess;
            }
            printf("Word : %s\n",guessed);
            printf("-----------------------------");
            correct = true;
        }else{
            printf("-----------------------------");
            printf("\nThe guess was incorrect!\n");
            printf("Guess another letter!\n");
            printf("-----------------------------");
            userHealth = userHealth - 1;
            printf("-----------------------------");
            printf("\nGuess left :%d\n",userHealth);
            printf("\nWord : %s\n",guessed);
            printf("-----------------------------");
            correct = true;
        }
        if(userHealth <= 0){
            printf("\n------------------------------------------------");
            printf("\nYou guessed incorrectly 5 times.\nGame over!\n");
            printf("The word was %s\n",word);
            printf("------------------------------------------------");
        }
    }
}
