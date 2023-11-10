#include "text_editor.h"

void moveUp(TextContent *text);
void moveDown(TextContent *text);
void moveLeft(TextContent *text);
void moveRight(TextContent *text, int numCols);
Line *getCurrentLine(TextContent *text, int row);
void moveToPosition(TextContent *text, int targetRow, int targetCol);

/**
 * moveCursor - Moves the cursor to the specified row and column.
 *
 * @text: Pointer to the TextContent struct.
 * @direction: Direction to move the cursor (U, D, L, R).
 *
 * Return: void
 */
void moveCursor(TextContent *text, char direction)
{
	switch (direction)
	{
		case 'U':
			moveUp(text);
			break;
		case 'D':
			moveDown(text);
			break;
		case 'L':
			moveLeft(text);
			break;
		case 'R':
			moveRight(text, getLineLength(text, text->numLines));
			break;
		default:
			fprintf(stderr, "Invalid direction: %c\n", direction);
			return;
	}
}

/**
 * moveUp - Moves the cursor up by one line.
 *
 * @text: Pointer to the TextContent struct.
 *
 * Return: void
 */
void moveUp(TextContent *text)
{
	int currentRow;

	currentRow = getCurrentRow(text);
	moveToPosition(text, currentRow - 1, getCurrentCol(text));
}

/**
 * moveDown - Moves the cursor down by one line.
 *
 * @text: Pointer to the TextContent struct.
 *
 * Return: void
 */
void moveDown(TextContent *text)
{
	int currentRow;

	currentRow = getCurrentRow(text);
	moveToPosition(text, currentRow + 1, getCurrentCol(text));
}

/**
 * moveLeft - Moves the cursor left by one column.
 *
 * @text: Pointer to the TextContent struct.
 *
 * Return: void
 */
void moveLeft(TextContent *text)
{
	int currentRow;
	int currentCol;

	currentCol = getCurrentCol(text);
	currentRow = getCurrentRow(text);

	if (currentCol > 0)
	{
		moveToPosition(text, currentRow, currentCol - 1);
	}
	else if (currentRow > 1)
	{
		moveUp(text);
		moveToPosition(text, currentRow - 1, getLineLength(text, currentRow - 1));
	}
	else
	{
		fprintf(stderr, "Error: Cannot move left\n");
	}
}

/**
 * getCurrentLine - Gets the current line.
 *
 * @text: Pointer to the TextContent struct.
 * @row: Row of the current line.
 *
 * Return: Pointer to the current line.
 */
Line *getCurrentLine(TextContent *text, int row)
{
	int currentRow;
	Line *currentLine;

	if (!text || row < 1 || row > text->numLines)
	{
		return (NULL);
	}

	currentLine = text->firstLine;

	for (currentRow = 1; currentRow < row && currentLine; currentRow++)
	{
		currentLine = currentLine->next;
	}

	return (currentLine);
}

/**
 * moveRight - Moves the cursor right by one column.
 *
 * @text: Pointer to the TextContent struct.
 * @numCols: Number of columns in the TextContent struct.
 *
 * Return: void
 */
void moveRight(TextContent *text, int numCols)
{
	int currentRow = getCurrentRow(text);
	int currentCol = getCurrentCol(text);
	int lineLength, targetCol;

	Line *currentLine = getCurrentLine(text, currentRow);

	if (!currentLine)
	{
		fprintf(stderr, "Invalid position: (%d, %d)\n", currentRow, currentCol);
		return;
	}

	lineLength = strlen(currentLine->text);

	if (currentCol == lineLength)
	{
		if (currentRow < text->numLines)
		{
			moveDown(text);
			moveToPosition(text, currentRow + 1, 0);
		}
		else
		{
			fprintf(stderr, "Error: Cannot move right\n");
		}
	}
	else
	{
		targetCol = currentCol + 1;
		targetCol = (targetCol > numCols) ? numCols : targetCol;
		moveToPosition(text, currentRow, targetCol);
	}
}

/**
 * handleError - Handles errors.
 *
 * @message: Error message.
 *
 * Return: void
 */
void handleError(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(EXIT_FAILURE);
}

/**
 * moveToPosition - Moves the cursor to the specified row and column.
 *
 * @text: Pointer to the TextContent struct.
 * @targetRow: Target row to move the cursor to.
 * @targetCol: Target column to move the cursor to.
 *
 * Return: void
 */
void moveToPosition(TextContent *text, int targetRow, int targetCol)
{
	int lineLength;

	Line *currentLine = getCurrentLine(text, targetRow);

	if (!currentLine)
	{
		handleError("Error: Invalid target position");
	}

	lineLength = strlen(currentLine->text);

	if (targetCol < 0 || targetCol > lineLength)
	{
		handleError("Error: Invalid target position");
	}

	text->cursorRow = targetRow;
	text->cursorCol = targetCol;

	printf("Moving to position: (%d, %d)\n", targetRow, targetCol);
}
