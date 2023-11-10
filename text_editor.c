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
	int position, count, currentRow, currentCol, currentPosition;
	char fileName[100], newText[1024], direction;

	TextContent text_content;

	initializeTextEditor(&text_content);

	while (1)
	{
		printf("\nEnter a command (or q to quit): ");

		if (getline(&input, &inputSize, stdin) == -1)
		{
			break;
		}

		if (strcmp(input, "q\n") == 0 || strcmp(input, "quit\n") == 0)
		{
			break;
		}
		else if (strcmp(input, "s\n") == 0)
		{
			displayText(&text_content);
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
		else if (strcmp(input, "d\n") == 0)
		{
			printf("Enter the position to delete: ");
			position = -1;

			if (scanf("%d", &position) != 1)
			{
				position = text_content.numLines;
				clearBuffer();
				continue;
			}

			printf("Enter the number of characters to delete: ");
			count = -1;

			if (scanf("%d", &count) != 1)
			{
				count = 1;
				clearBuffer();
				continue;
			}

			deleteText(&text_content, position, count);

			clearBuffer();

			displayText(&text_content);
		}
		else if (strcmp(input, "w\n") == 0)
		{
			printf("Enter the filename to save: ");

			if (scanf("%99s", fileName) != 1)
			{
				clearBuffer();
				continue;
			}

			saveTextToFile(&text_content, fileName);
			printf("Text saved to %s\n", fileName);
			displayText(&text_content);
			clearBuffer();
		}
		else if (strcmp(input, "r\n") == 0)
		{
			printf("Enter the filename to load: ");

			if (scanf("%99s", fileName) != 1)
			{
				clearBuffer();
				continue;
			}

			loadTextFromFile(&text_content, fileName);
			printf("Text loaded from %s\n", fileName);
			clearBuffer();
		}
		else if (strcmp(input, "e\n") == 0)
		{
			displayText(&text_content);

			printf("Enter the direction to move the cursor (U, D, L, R): ");

			if (scanf(" %c", &direction) != 1)
			{
				clearBuffer();
				continue;
			}

			currentRow = getCurrentRow(&text_content);
			currentCol = getCurrentCol(&text_content);

			moveCursor(&text_content, direction);

			if ((currentRow == getCurrentRow(&text_content)) &&
					(currentCol == getCurrentCol(&text_content)))
			{
				printf("Error: Cursor movement failed\n");
				clearBuffer();
				continue;
			}

			displayText(&text_content);
			clearBuffer();

			printf("Enter the new text: ");

			if (scanf(" %[^\n]", newText) != 1)
			{
				clearBuffer();
				continue;
			}

			currentPosition = getCurrentPosition(&text_content);
			editText(&text_content, currentPosition, newText);
			displayText(&text_content);
			clearBuffer();
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
