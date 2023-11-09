#include "text_editor.h"


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
