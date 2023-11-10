#include "text_editor.h"

static Line *findLine(TextContent *text, int position);
static void editLineText(Line *line, const char *newText);

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
	Line *lineToEdit = NULL;

	if (!text || position < 0 || position > text->numLines || !newText)
	{
		fprintf(stderr, "Invalid arguments\n");
		return;
	}

	lineToEdit = findLine(text, position);

	if (lineToEdit)
	{
		editLineText(lineToEdit, newText);
	}
}

/**
 * editLineText - edits the text of a given line
 *
 * @line: pointer to the Line struct
 * @newText: new text to replace the old text
 *
 * Return: void
 */
static void editLineText(Line *line, const char *newText)
{
	char *editableText;
	size_t len;

	if (!line || !newText)
	{
		fprintf(stderr, "Invalid arguments\n");
		return;
	}

	free(line->text);
	line->text = NULL;

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

	line->text = editableText;

	if (!line->text)
	{
		perror("Error duplicating text");
		exit(EXIT_FAILURE);
	}
}

/**
 * findLine - finds the line at a given position
 *
 * @text: pointer to the TextContent struct
 * @position: position of the line to find
 *
 * Return: pointer to the Line struct
 * or NULL if not found
 * or invalid arguments
 */
static Line *findLine(TextContent *text, int position)
{
	Line *current;
	int i;

	current = text->firstLine;

	for (i = 0; i < position; i++)
	{
		if (!current)
		{
			fprintf(stderr, "Invalid arguments\n");
			return (NULL);
		}

		current = current->next;
	}

	return (current);
}
