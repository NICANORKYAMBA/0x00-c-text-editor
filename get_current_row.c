#include "text_editor.h"

/**
 * getCurrentRow - Gets the current row of the cursor.
 *
 * @text: Pointer to the TextContent struct.
 *
 * Return: Current row of the cursor.
 */
int getCurrentRow(TextContent *text)
{
	int currentRow;
	Line *currentLine;

	currentRow = 1;
	currentLine = text->firstLine;

	while (currentLine && currentRow < text->numLines)
	{
		currentRow++;
		currentLine = currentLine->next;
	}

	return (currentRow);
}
