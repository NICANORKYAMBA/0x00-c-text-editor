#include "text_editor.h"

/**
 * editText - edits the text at a given position
 *	in the text editor
 *
 * @text: pointer to the TextContent struct
 * @position: position of the text to edit
 * @newText: new text to replace the old text
 *
 * Return: void
 */
void editText(TextContent *text, int position, const char *newText)
{
	Line *current;
	int i;
	size_t len;
	char *editableText;

	if (!text || position < 0 || position > text->numLines || !newText)
	{
		fprintf(stderr, "Invalid arguments\n");
		return;
	}

	current = text->firstLine;

	for (i = 0; i < position; i++)
	{
		if (!current)
		{
			fprintf(stderr, "Invalid position\n");
			return;
		}

		current = current->next;
	}

	free(current->text);
	current->text = NULL;

	editableText = strdup(newText);

	if (!editableText)
	{
		perror("Error duplicating text");
		exit(EXIT_FAILURE);
	}

	len = strlen(editableText);

	if (len > 0 && editableText[len - 1] == '\n')
	{
		editableText[len - 1] = '\0';
	}

	current->text = editableText;

	if (!current->text)
	{
		perror("Error duplicating text");
		exit(EXIT_FAILURE);
	}
}
