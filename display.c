#include "text_editor.h"

/**
 * displayText - displays text in the editor
 *
 * @text: text to display
 *
 * Return: Void (Nothing)
 */
void displayText(const TextContent *text)
{
	Line *currentLine;

	if (!text)
		return;

	currentLine = text->firstLine;

	while (currentLine)
	{
		printf("%s", currentLine->text);
		currentLine = currentLine->next;
	}
}
