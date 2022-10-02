#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "conio.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG 1 // 1 ON | 0 OFF

/* Global variables */
char guess[20];
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

	int length;
	int len;
	int found = 0;
	int found1 = 0;
	int count;
	int wordcount = 1;
	signed int point = 100;
	
	bool correct = false;
	bool error = false;
	bool next = true;

	char mode[10];
	char input[20];
	input[19] = '\0';
	char temp[20];

	/* Print Instructions */
	printf("***********************************\n");
	printf("FUNNY Q&A GAME\n");
	printf("***********************************\n");
	printf("INSTRUCTION\n");
	printf("There are 2 mode you can choose.\n");
	printf("+ Mode 1: Input a letter\n");
	printf("+ Mode 2: Input full answer\n");
	printf("***********************************\n");
	printf("\n");

	/* Loop for each Q&A */
	for (int i = 0; i < numberOfQuestions; i++)
	{
		/* Print Question */
		printf("-----------------------------------------------------------------------\n");
		printf("%s\n", questions[i]);
		printf("-----------------------------------------------------------------------\n");
		printf("\n");

		/* DEBUG MODE to print answer */
		#if (DEBUG == 1)
		{
			printf("%s\n", answers[i]);
			printf("\n");
		}
		#else
		{

		}
		#endif

		/* Variables */
		length = strlen(answers[i]);
		correct = false;
		wordcount = 1;

		/* Creat guess array to store input answer */
		for (int j = 0; j < 15; j++)
		{
			if (j < length)
			{
				guess[j] = '-';
				if (answers[i][j] == ' ')
				{
					guess[j] = ' ';
					wordcount = wordcount + 1;
				}
				else
				{
					wordcount = wordcount + 0;
				}
			}
			else
			{
				guess[j] = NULL;
			}
		}

		/* Loop for check if answer is correct and continue to game */
		while (correct == false && next == true)
		{			
			/* Check point */
			if (point <= 0)
			{
				printf("YOU ARE LOSE.\n");
				next = false;
				break;
			}
			else
			{

			}
			
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
			CHECK = scanf("%s", &mode);
			len = strlen(mode);
			printf("\n");

			/* Loop for check MODE input */
			while (len > 1 || (mode[0] != '1' && mode[0] != '2'))
			{
				printf("\nERROR! Please type the number 1 or 2 ONLY\n");
				printf("Input 1 for MODE 1 or 2 for MODE 2: ");
				CHECK = scanf("%s", &mode);
				len = strlen(mode);
				printf("\n");
			}

			/* DEBUG MODE */
			#if (DEBUG == 1)
			{
				printf("%s\n", answers[i]);
				printf("\n");
			}
			#else
			{

			}
			#endif

			/*  MODE 1 */
			if (mode[0] == '1')
			{
				/* Check input letter for MODE 1 */
				printf("Please input a letter: ");
				CHECK = scanf("%s", &input);
				len = strlen(input);
				//printf("%d\n", len);

				/* Loop check 1 letter */
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
						found1 = found1 + 1;
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

				/* Check full answer in MODE 1 */
				printf("||%d||\n", found1);
				if (wordcount > 1)
				{
					if (found1 == (length-(wordcount-1)))
					{
						printf("\nCORRECT! Answer is %s.\n", guess);
						printf("YOU ARE THE WINNER WITH %d POINTS\n", point);
						printf("\n");
						found1 = 0;
						correct = true;
					}
				}
				else
				{
					if (found1 == length)
					{
						printf("\nCORRECT! Answer is %s.\n", guess);
						printf("YOU ARE THE WINNER WITH %d POINTS\n", point);
						printf("\n");
						found1 = 0;
						correct = true;
					}
					else
					{

					}
				}
			}
			else /* MODE 2 */
			{
				/* Check input answer for MODE 2 */
				printf("Please input full answer: ");
				CHECK = scanf("%*[\n]");
				fgets(input, length+1, stdin);
				len = strlen(input);
				if (len != length)
				{
					error = true;
				}

				/* Loop for check input full answer */
				while (error == true)
				{
					count = 0;
					printf("\nERROR! Please input full answer AGAIN: ");
					CHECK = scanf("%*[\n]");
					fgets(input, length+1, stdin);
					len = strlen(input);
					if (len != length)
					{
						error = true;
					}
					else
					{
						for (int l = 0; l < len; l++)
						{
							if ((input[l] < 'A' || input[l] > 'Z') && !(input[1] == ' '))
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
					if (input[m] == answers[i][m])
					{
						found = found + 1;
						found1 = 0;
					}
					else
					{
						found = found + 0;
					}
				}

				/* Calc point after check */
				if (found == length)
				{
					strcpy(guess, answers[i]);
					printf("\nCORRECT! Answer is %s.\n", guess);
					printf("\n");
					printf("YOU ARE THE WINNER WITH %d POINTS\n", point);
					printf("\n");
					found = 0;
					correct = true;
				}
				else
				{
					point = point - 20;
					printf("\nNOT CORRECT! The answer is %s. Player point = %d\n", guess, point);
					printf("\n");
					found = 0;
				}
			}

			/* Check if player want to continue or not */
			if (correct == true)
			{
				if (i < numberOfQuestions - 1)
				{
					printf("Do you want to play next question? (Y/N): ");
					CHECK = scanf("%s", &input);
					CHECK = getchar();
					printf("\n");
					if (input[0] == 'Y')
					{
						correct = false;
						next = true;
						break;
					}
					else if (input[0] == 'N')
					{
						next = false;
						break;
					}
					else
					{

					}
				}
				else
				{
					next = false;
				}
			}
			else
			{
				
			}
		}

		/* Check if player want to continue or not */
		if (next == false)
		{
			printf("THANK YOU FOR PLAYING GAME!\n");
			break;
		}
		else
		{

		}
	}
}