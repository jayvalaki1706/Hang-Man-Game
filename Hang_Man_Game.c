#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int getLength(char *IN[])
{
    int index = 0;
    while (1)
    {
        if (IN[index] == NULL)
        {
            return index;
        }
        else
        {
            index++;
        }
    }
};

char *stickman(int i)
{
    if (i > 5)
    {
        return "invalid input chance---";
    }
    else if (i == 0)
    {
        printf("   +---+\n   |   |\n   O   |\n  /|\\  |\n  / \\  |\n       |\n   =========");
    }
    else if (i == 1)
    {
        printf("   +---+\n   |   |\n   O   |\n  /|\\  |\n       |\n       |\n   =========");
    }
    else if (i == 2)
    {
        printf("   +---+\n   |   |\n   O   |\n   |   |\n       |\n       |\n   =========");
    }
    else if (i == 3)
    {
        printf("   +---+\n   |   |\n   O   |\n       |\n       |\n       |\n   =========");
    }
    else if (i == 4)
    {
        printf("   +---+\n   |   |\n       |\n       |\n       |\n       |\n   =========");
    }
    else if (i == 5)
    {
        printf("   +---+\n       |\n       |\n       |\n       |\n       |\n   =========");
    }
    return 0;
};

int getRand(int lower, int upper)
{
    time_t t;
    srand((unsigned)time(&t));
    int num = (rand() % (upper - lower)) + lower;
    return num;
}

int main()
{

    system("clear");
    char *words_lib[9] = {"ball", "funny", "throw", "catch", "fun", "axe", "lmao", "dead"};
    int elem = getRand(1, getLength(words_lib));
    char *RandomWordIs = words_lib[elem];
    printf("%s\n", words_lib[elem]);
    int StringLength = strlen(RandomWordIs);
    // strlen gets the length of an string (int)

    int idk = 0;
    int chances = StringLength;
    // string length is the amount of chances user will get

    printf("Hi, Welcome to Hangman game; try guessing the first letter out of %d", StringLength);
    printf(" letters\n");
    printf("Possible words----> ");

    for (int j = 0; j < getLength(words_lib); j++)
    {

        printf("%s", words_lib[j]);
        printf(", ");
    }

    for (int i = 0; i < StringLength; i++)
    {
        char guess;

        printf("\nGUESS THE LETTER");
        printf("(");
        printf("%d", chances);
        printf("): ");
        scanf(" %c", &guess);

        if (i == StringLength - 1)
        {

            if (guess == RandomWordIs[idk])
            {

                system("clear");
                printf("You won!! the word was: ");
                printf("%s", RandomWordIs);
                printf("%s", "\n");
                idk++;
            }

            else
            {

                system("clear");
                printf("You lose :( lmao dead\n");
                stickman(0);
            }
        }

        else if (guess == RandomWordIs[idk])
        {

            printf("right guess!!\n");
            idk++;
        }

        else
        {

            idk++;
            chances--;
            printf("wrong guess\n");
            stickman(chances);
        }
    }
}
