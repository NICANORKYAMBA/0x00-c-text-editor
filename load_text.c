#include "text_editor.h"

FILE *openFile(const char *fileName);
void insertLine(TextContent *text, const char *line);
void insertNewLine(TextContent *text);

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
	size_t len;
	char *fullStop;

	if (!text || !fileName)
	{
		fprintf(stderr, "Invalid arguments\n");
		return;
	}

	file = openFile(fileName);

	if (!file)
	{
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

		fullStop = strchr(buffer, '.');

		if (fullStop)
		{
			insertLine(text, buffer);
			insertNewLine(text);
			insertLine(text, fullStop + 1);
			insertNewLine(text);
		}
		else
		{
			insertLine(text, buffer);
			insertNewLine(text);
		}
	}

	fclose(file);
}

/**
 * openFile - opens a file for reading
 *
 * @fileName: name of the file to open
 *
 * Return: pointer to the file
 */
FILE *openFile(const char *fileName)
{
	FILE *file = fopen(fileName, "r");

	if (!file)
	{
		perror("Error opening file");
	}

	return (file);
}

/**
 * insertLine - inserts a line into the text editor
 *
 * @text: pointer to the TextContent struct
 * @line: line to insert
 *
 * Return: void
 */
void insertLine(TextContent *text, const char *line)
{
	insertText(text, text->numLines, line);
}

/**
 * insertNewLine - inserts a new line into the text editor
 *
 * @text: pointer to the TextContent struct
 *
 * Return: void
 */
void insertNewLine(TextContent *text)
{
	insertText(text, text->numLines, "\n");
}
