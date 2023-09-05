#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include<ctype.h>
typedef struct words{ // struct defined for the bank of words
    char * three[250];
    char * four[250];
    char * five[250];
    char * six[250];
    char * seven[250];
}Words;

char * generateWord(int len);
void printGame(int count);
void getGuess(int len, int *guess, char * word, int * count, char * dash, int right, int check, char * guesses);
void printBottom(int len, char * dash);
void gameOver(int right, int guess);
