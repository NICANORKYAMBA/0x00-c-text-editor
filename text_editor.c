#include "text_editor.h"

void clearBuffer(void);

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *input = NULL;
	size_t inputSize = 0;
	int position;

	TextContent text_content;

	initializeTextEditor(&text_content);

	while (1)
	{
		printf("Enter a command (or q to quit): ");

		if (getline(&input, &inputSize, stdin) == -1)
		{
			break;
		}

		if (strcmp(input, "q\n") == 0 || strcmp(input, "quit\n") == 0)
		{
			break;
		}
		else if (strcmp(input, "i\n") == 0)
		{
			printf("Enter the text to insert: ");

			if (getline(&input, &inputSize, stdin) == -1)
			{
				break;
			}

			printf("Enter the position to insert: ");
			position = -1;

			if (scanf("%d", &position) != 1)
			{
				position = text_content.numLines;
				clearBuffer();
			}

			insertText(&text_content, position, input);

			clearBuffer();

			displayText(&text_content);
		}
		else
		{
			printf("Invalid command\n");
			clearBuffer();
		}
	}

	free(input);
	cleanupTextEditor(&text_content);

	return (0);
}

/**
 * clearBuffer - Clears the input buffer
 *
 * Return: void
 */
void clearBuffer(void)
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
	{
		;
	}
}
