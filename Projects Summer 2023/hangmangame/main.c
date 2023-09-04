#include "hangman.h"

int main(void)
{
    int len;
    printf("\n    ----Welcome To Hangman!----\n");
    printf("\nHow long do you want your word to be?\nEnter an integer between 3 & 7: ");
    scanf(" %d", &len);
    if (len>7 || len<3)
    {
        puts("\nI'm sorry, you'll need to start over. You entered an integer outside of the bounds!\n");
    }
    if (len<=7 && len>=3)
    {
    char * word = generateWord(len);
    printf("\n");
    char temp[] = "----------";
    char * dash = malloc(len*sizeof(char));
    for(int i = 0; i<len; i++)
    {
        dash[i] = temp[i];
    }
    char * guesses = malloc(26*sizeof(char));
    int guess = 0;
    int count = 0;
    int right = 0;
    int check = 0;
    while(count < 7 && (strcmp(dash,word) != 0))
    {
    getGuess(len, &guess, word, &count, dash, right, check, guesses);
    printGame(count);
    printBottom(len, dash);
    
    }
    if(count == 7)
    {
        gameOver(right, guess);
        printf("The word was: ");
        for(int i = 0; i<len; i++)
        {
            printf("%c", word[i]);
        }
        printf("\n");
        
    }
    if(strcmp(word, dash)==0)
    {
        right++;
        gameOver(right, guess);
        
    }
    free(dash);
    free(guesses);
    }
    

}