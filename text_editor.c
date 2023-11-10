#include "text_editor.h"

void clearBuffer(void);
void handleInsertCommand(TextContent *text_content, char *input);
void handleDeleteCommand(TextContent *text_content);
void handleSaveCommand(TextContent *text_content);
void handleLoadCommand(TextContent *text_content);
void handleMoveAndEditCommand(TextContent *text_content);

/**
 * processCommand - Processes a command
 *
 * @text_content: Text content
 * @input: Command input
 *
 * Return: void
 */
void processCommand(TextContent *text_content, char *input)
{
	if (strcmp(input, "s\n") == 0)
	{
		displayText(text_content);
	}
	else if (strcmp(input, "i\n") == 0)
	{
		handleInsertCommand(text_content, input);
	}
	else if (strcmp(input, "d\n") == 0)
	{
		handleDeleteCommand(text_content);
	}
	else if (strcmp(input, "w\n") == 0)
	{
		handleSaveCommand(text_content);
	}
	else if (strcmp(input, "r\n") == 0)
	{
		handleLoadCommand(text_content);
	}
	else if (strcmp(input, "e\n") == 0)
	{
		handleMoveAndEditCommand(text_content);
	}
	else
	{
		printf("Invalid command\n");
		clearBuffer();
	}
}

/**
 * handleInsertCommand - Handles the insert command
 *
 * @text_content: Text content
 * @input: Command input
 *
 * Return: void
 */
void handleInsertCommand(TextContent *text_content, char *input)
{
	int position = -1;
	size_t inputSize = 0;

	printf("Enter the text to insert: ");

	if (getline(&input, &inputSize, stdin) == -1)
	{
		return;
	}

	printf("Enter the position to insert: ");

	if (scanf("%d", &position) != 1)
	{
		position = text_content->numLines;
		clearBuffer();
	}

	insertText(text_content, position, input);
	clearBuffer();
	displayText(text_content);
}

/**
 * handleDeleteCommand - Handles the delete command
 *
 * @text_content: Text content
 *
 * Return: void
 */
void handleDeleteCommand(TextContent *text_content)
{
	int position, count = -1;

	printf("Enter the position to delete: ");

	if (scanf("%d", &position) != 1)
	{
		position = text_content->numLines;
		clearBuffer();
		return;
	}

	printf("Enter the number of characters to delete: ");

	if (scanf("%d", &count) != 1)
	{
		count = 1;
		clearBuffer();
	}

	deleteText(text_content, position, count);
	clearBuffer();
	displayText(text_content);
}

/**
 * handleSaveCommand - Handles the save command
 *
 * @text_content: Text content
 *
 * Return: void
 */
void handleSaveCommand(TextContent *text_content)
{
	char fileName[100];

	printf("Enter the filename to save: ");

	if (scanf("%99s", fileName) != 1)
	{
		clearBuffer();
		return;
	}

	saveTextToFile(text_content, fileName);

	printf("Text saved to %s\n", fileName);
	displayText(text_content);
	clearBuffer();
}

/**
 * handleLoadCommand - Handles the load command
 *
 * @text_content: Text content
 *
 * Return: void
 */
void handleLoadCommand(TextContent *text_content)
{
	char fileName[100];

	printf("Enter the filename to load: ");

	if (scanf("%99s", fileName) != 1)
	{
		clearBuffer();
		return;
	}

	loadTextFromFile(text_content, fileName);

	printf("Text loaded from %s\n", fileName);
	clearBuffer();
}

/**
 * handleMoveAndEditCommand - Handles the move and edit command
 *
 * @text_content: Text content
 *
 * Return: void
 */
void handleMoveAndEditCommand(TextContent *text_content)
{
	char direction;
	int currentRow, currentCol, currentPosition;
	char newText[1024];

	displayText(text_content);

	printf("Enter the direction to move the cursor (U, D, L, R): ");

	if (scanf(" %c", &direction) != 1)
	{
		clearBuffer();
		return;
	}

	currentRow = getCurrentRow(text_content);
	currentCol = getCurrentCol(text_content);

	moveCursor(text_content, direction);

	if ((currentRow == getCurrentRow(text_content)) &&
			(currentCol == getCurrentCol(text_content)))
	{
		printf("Error: Cursor movement failed\n");
		clearBuffer();
		return;
	}

	displayText(text_content);
	clearBuffer();

	printf("Enter the new text: ");
	if (scanf(" %[^\n]", newText) != 1)
	{
		clearBuffer();
		return;
	}

	currentPosition = getCurrentPosition(text_content);
	editText(text_content, currentPosition, newText);
	displayText(text_content);
	clearBuffer();
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
