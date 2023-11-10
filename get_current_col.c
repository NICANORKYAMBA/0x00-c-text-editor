#include "text_editor.h"

/**
 * getCurrentCol - Gets the current column of the cursor.
 *
 * @text: Pointer to the TextContent struct.
 *
 * Return: Current column of the cursor.
 */
int getCurrentCol(TextContent *text)
{
	int currentCol;
	Line *currentLine;

	currentCol = 0;
	currentLine = text->firstLine;

	while (currentLine)
	{
		if (currentLine == text->lastLine)
		{
			return (currentCol + strlen(currentLine->text));
		}
		else
		{
			currentCol += strlen(currentLine->text) + 1;
		}

		currentLine = currentLine->next;
	}

	return (currentCol);
}
