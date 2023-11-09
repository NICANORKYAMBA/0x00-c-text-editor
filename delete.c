#include "text_editor.h"

void deleteLine(TextContent *text, Line *current, Line *prevLine);
char *deleteTextInLine(const char *lineText, int position, int length);

/**
 * deleteLine - deletes a line from the text file
 *
 * @text: the text file to be edited
 * @current: the line to be deleted
 * @prevLine: the previous line in the text file
 *
 * Return: void
 */
void deleteLine(TextContent *text, Line *current, Line *prevLine)
{
	Line *nextLine = current->next;

	free(current->text);
	free(current);

	if (prevLine == NULL)
	{
		text->firstLine = nextLine;
	}
	else
	{
		prevLine->next = nextLine;
	}

	text->numLines--;

	if (nextLine == NULL)
	{
		text->lastLine = prevLine;
	}
}

/**
 * deleteTextInLine - deletes a portion of text in a line
 *
 * @lineText: the text in the line
 * @position: the starting position of the deletion
 * @length: the number of characters to delete
 *
 * Return: the modified line text
 */
char *deleteTextInLine(const char *lineText, int position, int length)
{
	int lineLength = strlen(lineText);
	char *newText;

	if (position + length >= lineLength)
	{
		return (NULL);
	}

	newText = (char *)malloc((lineLength - length + 1) * sizeof(char));
	strncpy(newText, lineText, position);
	strncpy(newText + position,
			lineText + position + length,
			lineLength - position - length);
	newText[lineLength - length] = '\0';

	return (newText);
}

/**
 * deleteText - deletes a portion of a text file
 *
 * @text: the text file to be edited
 * @position: the starting position of the deletion
 * @length: the number of characters to delete
 *
 * Return: void
 */
void deleteText(TextContent *text, int position, int length)
{
	Line *current, *prevLine = NULL;
	char *newText;
	int i;

	if (position < 0 || position >= text->numLines || length <= 0)
		return;

	current = text->firstLine;

	for (i = 0; i < position && current; i++)
	{
		prevLine = current;
		current = current->next;
	}

	if (current == NULL || current->text == NULL)
		return;

	newText = deleteTextInLine(current->text, position, length);

	if (newText != NULL)
	{
		free(current->text);
		current->text = newText;
	}
	else
	{
		deleteLine(text, current, prevLine);
	}
}
