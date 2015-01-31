/*
 *  guess2.c
 *  xch10
 *
 *	asks user to guess a hidden number (no external variables)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

void initialize_number_generator(void);
int new_secret_number(void);
void read_guesses(int secret_number);

int main()
{
	char command = '0';
	int secret_number = 0;
	
	printf("\n\nGuess the secret number between 1 and %d.\n\n", MAX_NUMBER);
	
	initialize_number_generator();
	
	do
	{
		secret_number = new_secret_number();
		
		printf("A new number has been chosen.\n");
		
		read_guesses(secret_number);
		
		printf("Play again? (Y/N) ");
		scanf(" %c", &command);
		printf("\n");
	} while (command == 'y' || command == 'Y');
	
	return 0;
}

/* 
 * initialize_number_generator: 
 *
 * initialize the random number generator using the
 * time of day
 */
void initialize_number_generator(void)
{
	srand((unsigned) time(NULL));
}

/*
 * randomly selects a number between a and MAX_NUMBER
 */
int new_secret_number(void)
{
	return rand() % MAX_NUMBER + 1;
}

/*
 * repeatedly reads user guesses and tells the user whether each guess is
 * too low, too high. or correct. When the guess is correct, prints the total
 * number of guesses and returns
 */
void read_guesses(int secret_number)
{
	int guess, num_guesses;
	guess = num_guesses = 0;
	
	for(;;)
	{
		num_guesses++;
		
		printf("Enter guess: ");
		scanf("%d", &guess);
		
		if (guess == secret_number)
		{
			printf("You won in %d guesses!\n\n", num_guesses);
			return;
		}
		else if (guess < secret_number)
			printf("Too low; try again.\n");
		else
			printf("Too high; try again.\n");
	}
}


