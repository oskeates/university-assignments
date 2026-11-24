#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define CODE_LENGTH 4
#define MIN_DIGIT 1
#define MAX_DIGIT 6
#define MAX_ATTEMPTS 10

//function prototypes
void generateSecret(int secret[], int size);
void printCode(int code[], int size);
void inputArray(int guess[], int size);
bool isValidGuess(int guess[], int size);
int countExact(int secret[], int guess[], int size);
int countMisplaced(int secret[], int guess[], int size);

int attemptsLeft = MAX_ATTEMPTS;

int main (void)
{
    srand(time(NULL));

    int secret[CODE_LENGTH], guess[CODE_LENGTH];
    bool leave = false;

    generateSecret(secret, CODE_LENGTH);

    printf("Welcome to code breaker!\n");
    printf("Guess the %d digit code. Each digit is between %d and %d.\n", CODE_LENGTH, MIN_DIGIT, MAX_DIGIT);
    printf("Enter -1 for any digit to quit.\n");

    while (attemptsLeft > 0)
    {
        printf("Attempts remaining: %d\n", attemptsLeft);

        //input validation
        do 
        {
            inputArray(guess, CODE_LENGTH);
            for (int i = 0; i < CODE_LENGTH; i++)
            {
                if (guess[i] == -1)
                {
                    printf("You quit. The secret code was: ");
                    printCode(secret, CODE_LENGTH);
                    leave = true;
                    break;
                }
            }
            if (leave)
            {
                break;
            }
        } 
        while (isValidGuess(guess, CODE_LENGTH) == false);

        if (leave)
        {
            break;
        }        

        attemptsLeft --;

        //printing the users guess
        printf("Your guess: \n");
        printCode(guess, CODE_LENGTH);

        //getting the number of exact and misplaced characters
        int exact = countExact(secret, guess, CODE_LENGTH);
        int misplaced = countMisplaced(secret, guess, CODE_LENGTH);

        //printing the exact and misplaced characters to the terminal
        printf("Correct position: %d | Wrong position: %d\n", exact, misplaced);

        //checking if the user has won
        //if they didn't win, lower attemptLeft by 1
        if (exact == CODE_LENGTH)
        {
            printf("You cracked the code in %d attempt(s)!\n", MAX_ATTEMPTS - attemptsLeft);
            break;
        }
        //if there are no attempts remaining give the losing message
        else if (attemptsLeft == 0)
        {
            printf("0 attempts remaining. The secret code was: ");
            printCode(secret, CODE_LENGTH);
        }
    
    }

}

//functions

//creates the secret code
void generateSecret(int secret[], int size)
{
    for (int i = 0; i < size; i++)
    {
        secret[i] = MIN_DIGIT + rand() % (MAX_DIGIT - MIN_DIGIT + 1);
    }
}


//prints whatever code needs to be printed
void printCode(int code[], int size)
{
    printf("[ ");

    for (int i = 0; i < size; i++)
    {
        printf("%d", code[i]);
        if (i < size - 1)
        {
            printf(" | ");
        }
    }

    printf(" ]\n");
}


//checks if the input is a valid guess
bool isValidGuess(int guess[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (guess[i] < MIN_DIGIT || guess[i] > MAX_DIGIT)
        {
            printf("Invalid guess, integers must be between %d and %d. Try again\n", MIN_DIGIT, MAX_DIGIT);
            return false;
        }
    }

    return true;
}


//gets an input from the user
void inputArray(int guess[], int size)
{
    printf("Enter your guess (%d digits seperated by spaces): ", size);
    //scanf(" %1d", &guess[0]);
    
    for (int i = 0; i < size; i++)
    {
        scanf(" %d", &guess[i]);
    }
}


//checks to see which integers are correct and in the right spot
int countExact(int secret[], int guess[], int size)
{
    int count = 0;

    for (int i = 0; i < size; i ++)
    {
        if (secret[i] == guess[i])
        {
            count += 1;
        }
    }

    return count;
}


//checks to see which integers are misplaced
int countMisplaced(int secret[], int guess[], int size)
{
    bool usedSecret[size], usedGuess[size];

    for (int i = 0; i < size; i++)
    {
        usedSecret[i] = (secret[i] == guess[i]);
        usedGuess[i] = (secret[i] == guess[i]);
    }


    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (usedSecret[i])
            {
                continue;
            }
        for (int j = 0; j < size; j++)
        {

            if (!usedGuess[j] && secret[i] == guess[j])
            {
                count ++;
                usedSecret[i] = true;
                usedGuess[j] = true;
                break;
            }
        }
    }

    return count;
}