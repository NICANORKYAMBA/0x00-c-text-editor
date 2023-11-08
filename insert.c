#include "text_editor.h"

/**
 * insertText - inserts a string at a given position
 *
 * @text: pointer to the TextContent struct
 * @position: position to insert the string
 * @line: string to insert
 *
 * Return: void
 */
void insertText(TextContent *text, int position, const char *line)
{
	char *newLine;
	int i;

	if (!text || !line)
		return;

	if (position < 0 || position > text->numLines)
		return;

	newLine = malloc(sizeof(char) * (strlen(line) + 1));

	if(!newLine)
		return;

	strcpy(newLine, line);

	if (position == text->numLines)
	{
		text->lastLine = realloc(text->lastLine, (text->numLines + 2) * sizeof(char *));
		
		if (!text->lastLine)
			return;

		text->lastLine[text->numLines] = newLine;
		text->lastLine[text->numLines + 1] = NULL;
		text->numLines++;
		return;

	}

	for (i = text->numLines; i > position; i--)
	{
		text->lastLine[i] = text->lastLine[i - 1];
	}

	text->lastLine[position] = newLine;
	text->numLines++;
}
