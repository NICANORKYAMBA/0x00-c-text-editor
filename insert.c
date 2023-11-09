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
	Line *newLine, *prevLine;
	int i;
	
	if (!text || !line)
		return;
	
	if (position < 0)
		position = 0;
	
	if (position > text->numLines)
		position = text->numLines;
	
	newLine = malloc(sizeof(Line));
	
	if (!newLine)
		return;
	
	newLine->text = strdup(line);
	newLine->next = NULL;
	
	if (position == 0)
	{
		newLine->next = text->firstLine;
		text->firstLine = newLine;
		
		if (text->numLines == 0)
		{
			text->lastLine = newLine;
		}
	}
	else if (position == text->numLines)
	{
		text->lastLine->next = newLine;
		text->lastLine = newLine;
	}
	else
	{
		prevLine = text->firstLine;
		
		for (i = 0; i < position - 1; i++)
		{
			prevLine = prevLine->next;
		}
		newLine->next = prevLine->next;
		prevLine->next = newLine;
	}
	
	text->numLines++;
}
