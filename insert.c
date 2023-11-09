#include "text_editor.h"

Line *createLine(const char *lineText);
void addToEmptyText(TextContent *text, Line *newLine);
void addToBeginning(TextContent *text, Line *newLine);
void addToEnd(TextContent *text, Line *newLine);
void addToMiddle(Line *prevLine, Line *newLine);

/**
 * createLine - creates a new line with the given text
 *
 * @lineText: the text to be assigned to the new line
 *
 * Return: a pointer to the new line
 */
Line *createLine(const char *lineText)
{
	Line *newLine = malloc(sizeof(Line));

	if (newLine)
	{
		newLine->text = strdup(lineText);
		newLine->next = NULL;
	}

	return (newLine);
}

/**
 * addToEmptyText - adds a new line to an empty text
 *
 * @text: pointer to the TextContent struct
 * @newLine: pointer to the new line to be added
 */
void addToEmptyText(TextContent *text, Line *newLine)
{
	text->firstLine = newLine;
	text->lastLine = newLine;
}

/**
 * addToBeginning - adds a new line to the beginning of the text
 *
 * @text: pointer to the TextContent struct
 * @newLine: pointer to the new line to be added
 */
void addToBeginning(TextContent *text, Line *newLine)
{
	newLine->next = text->firstLine;
	text->firstLine = newLine;

	if (text->numLines == 0)
	{
		text->lastLine = newLine;
	}
}

/**
 * addToEnd - adds a new line to the end of the text
 *
 * @text: pointer to the TextContent struct
 * @newLine: pointer to the new line to be added
 */
void addToEnd(TextContent *text, Line *newLine)
{
	if (text->numLines == 0)
	{
		addToEmptyText(text, newLine);
	}
	else
	{
		text->lastLine->next = newLine;
	}

	text->lastLine = newLine;
}

/**
 * addToMiddle - adds a new line to the middle of the text
 *
 * @prevLine: pointer to the line before the position
 * @newLine: pointer to the new line to be added
 */
void addToMiddle(Line *prevLine, Line *newLine)
{
	newLine->next = prevLine->next;
	prevLine->next = newLine;
}

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
	Line *newLine, *prevLine;
	int i;

	if (!text || !line)
		return;

	if (position < 0)
		position = 0;

	if (position > text->numLines)
		position = text->numLines;

	newLine = createLine(line);

	if (!newLine)
		return;

	if (position == 0)
		addToBeginning(text, newLine);
	else if (position == text->numLines)
		addToEnd(text, newLine);
	else
	{
		prevLine = text->firstLine;

		for (i = 0; i < position - 1; i++)
		{
			prevLine = prevLine->next;
		}

		addToMiddle(prevLine, newLine);
	}
	text->numLines++;
}
