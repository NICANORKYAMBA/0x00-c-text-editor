#include "text_editor.h"

/**
 * getLineLength - Gets the length of the current line.
 *
 * @text: Pointer to the TextContent struct.
 * @numLines: Number of lines in the TextContent struct.
 *
 * Return: Length of the current line.
 */
int getLineLength(TextContent *text, int numLines)
{
	int lineLength;
	Line *currentLine;

	currentLine = text->firstLine;

	while (currentLine && numLines > 1)
	{
		currentLine = currentLine->next;
		numLines--;
	}

	lineLength = strlen(currentLine->text);

	return (lineLength);
}
