#include "text_editor.h"

/**
 * cleanupTextEditor - cleans up the text editor.
 *
 * @editor: the text editor.
 *
 * Return: void.
 */
void cleanupTextEditor(TextContent *editor)
{
	Line *currentLine, *nextLine;

	if (!editor)
		return;

	currentLine = editor->firstLine;

	while (currentLine)
	{
		nextLine = currentLine->next;

		free(currentLine->text);
		free(currentLine);
		currentLine = nextLine;
	}

	editor->firstLine = NULL;
	editor->lastLine = NULL;
	editor->numLines = 0;
}
