#include "hangman.h"


char * generateWord(int len)
{
    // bank of words that can be randomly selected
    int length = 50;
    Words arr = {
        {"Act", "Air", "Art", "Ash", "Bag", "Bar", "Bed","Box", "Bus", "Car", "Cat", "Day", "Dog" ,"Ear", "Egg" ,"Eye" ,"Fan" ,"Fat" ,"Fly", "Fun", "Gap", "Gas", "God", "Hat", "Hen", "Hot", "Ice", "Ink", "Jam", "Job" ,"Key" ,"Law" ,"Leg", "Lip", "Man", "Map" ,"Net" ,"Nut" ,"Oak" ,"Pen", "Pig", "Pot" ,"Rat" ,"Run", "Sky" ,"Sun", "Toy" ,"Van", "Wax", "Zip"},
        {"Able", "Bake", "Bald", "Bass", "Beam", "Bend", "Bolt", "Bump", "Cage", "Calm", "Cash", "Clap", "Cope", "Cure", "Damp", "Dart", "Dawn", "Duck", "Dusk", "Exit", "Farm", "Firm", "Flea", "Flip", "Flow", "Fork", "Gasp", "Glow", "Grip", "Halt", "Haze", "Heap", "Hive", "Hurt", "Jazz", "Jolt", "Jump", "Keen", "Lamp", "Lend", "Lift", "Lose", "Mend", "Mint", "Nest", "Ooze", "Palm", "Pond", "Ramp", "Rust", "Seal"},
        {"About", "Ample", "Arrow", "Bacon", "Badge", "Baker", "Beach", "Bench", "Blaze", "Brave", "Cabin", "Cagey", "Calmly", "Candy", "Chain", "Chalk", "Cheek", "Cider", "Clasp", "Click", "Dance", "Ditch", "Doubt", "Dream", "Eager", "Elbow", "Fable", "Fancy", "Flame", "Flock", "Fruit", "Globe", "Grain", "Guide", "Hatch", "Hazel", "Ideal", "Image", "Jolly", "Judge", "Laser", "Lemon", "Lodge", "Magic", "Mango", "Mirth", "Noble", "Ocean", "Piano", "Pluck"},
        {"Accuse", "Banish", "Before", "Bright", "Cactus", "Castle", "Cherub", "Cinema", "Clumsy", "Crunch", "Danger", "Define", "Dinner", "Dreamy", "Drench", "Dubious", "Elegant", "Emblem", "Expert", "Famine", "Feline", "Fierce", "Flight", "Fumble", "Garden", "Genius", "Guitar", "Hammer", "Harbor", "Hearty", "Humble", "Hunger", "Ignite", "Invent", "Jester", "Jigsaw", "Jumble", "Justice", "Kernel", "Kitchen", "Lavish", "Lobster", "Manage", "Marble", "Mellow", "Mingle", "Napkin", "Nectar"},
        {"Abandon", "Balance", "Champion", "Discover", "Eclipse", "Fantasy", "Gallery", "Healthy", "Imagine", "Justice", "Kitchen", "Landscape", "Mansion", "Network", "Operate", "Passage", "Quality", "Rainbow", "Silence", "Talent", "Upgrade", "Village", "Warrior", "Zealous", "Abyssal", "Balance", "Calmest", "Diamond", "Elation", "Flaming", "Glisten", "Healing", "Imagine", "Jubilant", "Kissing", "Lyrical", "Midnight", "Nirvana", "Overflow", "Passion", "Quicken", "Radiant", "Shimmer", "Thistle", "Uplift", "Velvet", "Whisper", "Xenon"}
    };
    srand(time(NULL));
    int index = rand() % length;
    //figure out which integer the user entered
    if (len == 3)
    {
        return arr.three[index];
    }
    if (len == 4)
    {
        return arr.four[index];
    }
    if (len == 5)
    {
        return arr.five[index];
    }
    if (len == 6)
    {
        return arr.six[index];
    }
    if (len == 7)
    {
        return arr.seven[index];
    }
    return NULL;
}
void printGame(int count) // prints the board, will be called each time user guesses
// parameter is number of guesses user has gotten wrong; tells function which board to print
{
    switch (count) {
        case 0:
            printf("\t ______\n\t|     |\n\t|     \n\t|    \n\t|     \n\t|       \n    ____|____\n\n");
            break;
        case 1:
            printf("\t ______\n\t|     |\n\t|     0\n\t|    \n\t|     \n\t|       \n    ____|____\n\n");
            break;
        case 2:
            printf("\t ______\n\t|     |\n\t|     0\n\t|     |\n\t|     \n\t|       \n    ____|____\n\n");
            break;
        case 3:
            printf("\t ______\n\t|     |\n\t|     0\n\t|    -|\n\t|     \n\t|       \n    ____|____\n\n");
            break;
        case 4:
            printf("\t ______\n\t|     |\n\t|     0\n\t|    -|-\n\t|     \t       \n    ____|____\n\n");
            break;
        case 5:
            printf("\t ______\n\t|     |\n\t|     0\n\t|    -|-\n\t|     |\n\t|      \n    ____|____\n\n");
            break;
        case 6:
            printf("\t ______\n\t|     |\n\t|     0\n\t|    -|-\n\t|     |\n\t|    |   \n    ____|____\n\n");
            break;
        case 7:
            printf("\t ______\n\t|     |\n\t|     0\n\t|    -|-\n\t|     |\n\t|    | |   \n    ____|____\n\n");
            break;
    }
    }
void printBottom(int len, char * dash) // prints blanks or letter that have been guessed using an array
// parameters: the length of the word that will be guessed, and the array full of dashes that will be filled up by letters that are correct guesses
{
    for(int i = 0; i<len; i++)
    {
        printf("%c", dash[i]);
    }
    printf("\n");
    printf("\n");
    
}
void getGuess(int len, int *guess, char * word, int *count, char * dash, int right, int check, char * guesses) // this function takes the users guess and changes the dash array
// also prints the board 
//len is length of the word, guess is the number of guesses and needs to be pass by reference, word is the word the user is trying to guess
//dash is the array full of dashes that will fill up with correct guesses
//check will change depending on if the guess was corrct or not
//guesses is an array with all of the users past guesses
{
    check = 1;
    char * temp = malloc(sizeof(char));
    printf("What letter would you like to guess?\nMake sure it is lowercase!\nSo far you have guessed: ");
    for(int i = 0; i<*guess; i++)
    {
        printf("%c  ", guesses[i]);
    }
    printf("\n");
    scanf(" %c", temp);
    guesses[(*guess)] = temp[0];
    int array[7];
    for(int i = 0; i<len; i++)
    {
        array[i] = tolower(word[i]);
    }
    for(int i = 0; i<len; i++)
    {
        if(temp[0] == array[i]) // if guess is in the word
        {
            dash[i] = word[i];
            check=-1;
        }
}
    free(temp);
    if(check==-1) //correct guess
    {
        (*guess)++;
    }   
    if (check==1) // wrong guess
    {
        (*count)++;
        (*guess)++;
    } 
    
}



void gameOver(int right, int guess) // when game is over this is run
//0 is passed in if user ran out of guesses,
//1 is passed in if user correctly guessed the word
{
    if(right == 0)
    {
        printf("\nI'm sorry, you did not win.\nTry again next time!\n");
    }
    if(right ==1)
    {
        printf("Congratulations! You won in %d guesses!\n", guess);
    }
}