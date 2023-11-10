#include "text_editor.h"

/**
 * loadTextFromFile - reads a text file and loads it into the text editor
 *
 * @text: pointer to the TextContent struct
 * @fileName: name of the file to load the text from
 *
 * Return: void
 */
void loadTextFromFile(TextContent *text, const char *fileName)
{
	FILE *file;
	char buffer[1024];
	size_t len = 0;

	if (!text || !fileName)
	{
		fprintf(stderr, "Invalid arguments\n");
		return;
	}

	file = fopen(fileName, "r");

	if (!file)
	{
		perror("Error opening file");
		return;
	}

	cleanupTextEditor(text);
	initializeTextEditor(text);

	while (fgets(buffer, sizeof(buffer), file))
	{
		len = strlen(buffer);

		if (len > 0 && buffer[len - 1] == '\n')
		{
			buffer[len - 1] = '\0';
		}

		insertText(text, text->numLines, buffer);
		insertText(text, text->numLines, "\n");
	}

	fclose(file);
}
