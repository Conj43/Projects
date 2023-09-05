#include "hangman.h"

int main(void)
{
    int len;
    printf("\n    ----Welcome To Hangman!----\n");
    printf("\nHow long do you want your word to be?\nEnter an integer between 3 & 7: ");
    scanf(" %d", &len); // use user input for length of work
    if (len>7 || len<3)
    {
        puts("\nI'm sorry, you'll need to start over. You entered an integer outside of the bounds!\n"); // if an integer outside of bounds is entered
    }
    if (len<=7 && len>=3) // if input is between 3 and 7, you can go through the rest
    {
    char * word = generateWord(len); // randomly selects word from word bank
    printf("\n");
    char temp[] = "----------"; // initialize bottom of blanks
    char * dash = malloc(len*sizeof(char)); // allocate memory for dash array 
    for(int i = 0; i<len; i++)
    {
        dash[i] = temp[i]; 
    }
    char * guesses = malloc(26*sizeof(char)); // allocate memory for the array of past guesses by the user
    int guess = 0;
    int count = 0;
    int right = 0;
    int check = 0;
    while(count < 7 && (strcmp(dash,word) != 0)) // sort of a recursive function that loops until the user got too many guesses wong
    //or until the dash array is equal to the randomly generated word
    {
    getGuess(len, &guess, word, &count, dash, right, check, guesses);
    printGame(count);
    printBottom(len, dash); // these three lines print the board and blanks and dashes array
    
    }
    if(count == 7) // if user had too many guesses they lose the game and it tells them what the word was 
    {
        gameOver(right, guess);
        printf("The word was: ");
        for(int i = 0; i<len; i++)
        {
            printf("%c", word[i]);
        }
        printf("\n");
        
    }
    if(strcmp(word, dash)==0) // if user got each letter, this will print that they won the game
    {
        right++;
        gameOver(right, guess);
        
    }
    free(dash);
    free(guesses);
    }
    

}