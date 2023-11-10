#include "text_editor.h"

/**
 * saveTextToFile - save text to file from text editor
 *
 * @text: pointer to the TextContent struct
 * @fileName: name of the file to save the text
 *
 * Return: void
 */
void saveTextToFile(const TextContent *text, const char *fileName)
{
	FILE *file;
	Line *current;

	if (!text || !fileName)
	{
		fprintf(stderr, "Invalid arguments\n");
		return;
	}

	file = fopen(fileName, "w");

	if (!file)
	{
		perror("Error opening file");
		return;
	}

	current = text->firstLine;

	while (current)
	{
		fprintf(file, "%s", current->text);
		current = current->next;
	}

	fclose(file);
}
