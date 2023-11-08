#include "text_editor.h"


void cleanupTextEditor(TextContent *editor)
{
	Line *currentLine, *nextLine;

	currentLine = editor->firstLine;

	while (currentLine)
	{
		nextLine = currentLine;
		currentLine = currentLine->next;
		free(nextLine->text);
		free(nextLine);
	}

	free(editor);

	return;
}
