#include "text_editor.h"

/**
 * getCurrentPosition - Gets the current cursor position.
 *
 * @text: Pointer to the TextContent struct.
 *
 * Return: The current position.
 */
int getCurrentPosition(TextContent *text)
{
	int currentRow = getCurrentRow(text);
	int currentCol = getCurrentCol(text);

	return ((currentRow - 1) * (MAX_LINE_LENGTH + 1) + currentCol);
}
