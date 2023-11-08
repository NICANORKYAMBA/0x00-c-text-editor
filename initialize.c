#include "text_editor.h"

/**
 * initializeTextEditor - Initializes the text editor.
 *
 * @editor: Pointer to the text editor.
 *
 * Return: void.
 */
void initializeTextEditor(TextContent *editor)
{
	editor->firstLine = NULL;
	editor->lastLine = NULL;
	editor->numLines = 0;

}
