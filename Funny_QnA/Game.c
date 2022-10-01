#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "conio.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG

#ifdef DEBUG

#endif

/* Functions */

/* Global variables */
char guess[20];
bool correct = false;
int CHECK;

/* Function main */
int main()
{
	/* CREATE 5 QUESTIONS AND 5 ANSWER */
	char questions[][100] =
	{
		"1. What word is spelled incorrectly in every single dictionary?",
		"2. What goes up and down but can not move?",
		"3. I am so fragile that if you say my name, you will break me. What am I?",
		"4. What has one eye but can not see anything at all?",
		"5. What starts with e and ends with e but only has one letter in it?"
	};

	char answers[][15] =
	{
		"INCORRECTLY",
		"A STAIRCASE",
		"BREATH",
		"A NEEDLE",
		"AN ENVELOPE"
	};

	/* VARIABLES */
	int numberOfQuestions = sizeof(questions) / sizeof(questions[0]);

	int mode;
	int length;
	int len;
	int found = 0;
	int count;
	int wordcount = 1;
	int point = 100;
	
	bool error = false;

	char input[20];
	input[19] = '\0';
	char anscheck[15];

	printf("***********************************\n");
	printf("FUNNY Q&A GAME\n");
	printf("***********************************\n");
	printf("INSTRUCTION\n");
	printf("There are 2 mode you can choose.\n");
	printf("+ Mode 1: Input a letter\n");
	printf("+ Mode 2: Input full answer\n");
	printf("***********************************\n");
	printf("\n");

	for (int i = 0; i < numberOfQuestions; i++)
	{
		printf("-----------------------------------------------------------------------\n");
		printf("%s\n", questions[i]);
		printf("-----------------------------------------------------------------------\n");
		printf("\n");

		length = strlen(answers[i]);
		correct = false;

		for (int j = 0; j < 15; j++)
		{
			if (j < length)
			{
				guess[j] = '-';
			}
			else
			{
				guess[j] = NULL;
			}
		}

		while (correct == false)
		{
			/* Print anser */
			if (wordcount == 1)
			{
				printf("Answer has %d word, %d letters: %s. Player point = %d\n", wordcount, length, guess, point);

			}
			else
			{
				printf("Answer has %d words, %d letters: %s. Player point = %d\n", wordcount, length, guess, point);
			}
			printf("\n");

			/* Chose Mode */
			printf("Please choose MODE you want to play\n");
			printf("Input 1 for MODE 1 or 2 for MODE 2: ");
			CHECK = scanf("%d", &mode);
			CHECK = getchar();

			while (mode != 1 && mode != 2)
			{
				printf("\nERROR! Please type the number 1 or 2 ONLY\n");
				printf("Input 1 for MODE 1 or 2 for MODE 2: ");
				CHECK = scanf("%d", &mode);
				CHECK = getchar();
			}
			//printf("%s\n", answers[i]);

			/*  MODE 1 */
			if (mode == 1)
			{
				/* Check input letter for MODE 1 */
				printf("Please input a letter: ");
				CHECK = scanf("%s", &input);
				len = strlen(input);
				//printf("%d\n", len);

				while (input[0] < 'A' || input[0] > 'Z' || len > 1)
				{
					printf("\nERROR! Please input a letter AGAIN: ");
					CHECK = scanf("%s", &input);
				}

				/* Check if answer is correct in MODE 1 */
				for (int k = 0; k < length; k++)
				{
					if (answers[i][k] == input[0])
					{
						found = found + 1;
						guess[k] = answers[i][k];
					}
					else
					{
						found = found + 0;
					}
				}

				/* Calc point after check */
				if (found > 0)
				{
					point = point - 5;
					printf("\nCORRECT! There is %d \"%c\": %s. Player point = %d\n", found, input[0], guess, point);
					printf("\n");
					found = 0;
				}
				else
				{
					point = point - 10;
					printf("\nNOT CORRECT! There is %d \"%c\": %s. Player point = %d\n", found, input[0], guess, point);
					printf("\n");
				}
			}
			else /* MODE 2 */
			{
				/* Check input answer for MODE 2 */
				printf("Please input full answer: ");
				CHECK = scanf("%s", &input);
				len = strlen(input);
				if (len != length)
				{
					error = true;
				}

				while (error == true)
				{
					count = 0;
					printf("\nERROR! Please input full answer AGAIN: ");
					CHECK = scanf("%s", &input);
					len = strlen(input);
					if (len != length)
					{
						error = true;
					}
					else
					{
						for (int l = 0; l < len; l++)
						{
							if (input[l] < 'A' || input[l] > 'Z')
							{
								count = count + 1;
								// printf("\n%d\n", count);
							}
							else
							{
								count = count + 0;
							}
						}
						// printf("\n%d\n", count);
						if (count == 0)
						{
							error = false;
						}
						else
						{
							error = true;
							count = 0;
						}
					}
				}

				/* Check if answer is correct in MODE 2 */
				for (int m = 0; m < length; m++)
				{
					if (answers[i][m] == input[m])
					{
						found = found + 1;
						guess[m] = answers[i][m];
					}
					else
					{
						found = found + 0;
					}
				}

				/* Calc point after check */
				if (found == length)
				{
					printf("\nCORRECT! Answer is %s.\n", guess);
					printf("YOU ARE THE WINNER WITH %d POINTS\n", point);
					printf("\n");
					found = 0;
					break;
				}
				else
				{
					point = point - 20;
					printf("\nNOT CORRECT! There is %d \"%c\": %s. Player point = %d\n", found, input[0], guess, point);
					printf("\n");
				}
			}
			correct = true;
		}
	}
}