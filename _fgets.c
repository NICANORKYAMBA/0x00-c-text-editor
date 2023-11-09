#include "text_editor.h"

/**
 * customFgets - reads characters from a stream
 *               and stores them in a dynamically allocated buffer
 *
 * @stream: pointer to the stream to read from
 *
 * Return: pointer to the dynamically allocated buffer
 *         or NULL on error or end of file
 */
char *customFgets(FILE *stream)
{
	char *buffer = NULL;
	int size, c = 0;
	int capacity = 10;

	buffer = malloc(capacity);
	if (!buffer)
	{
		perror("customFgets");
		return (NULL);
	}

	while (1)
	{
		c = fgetc(stream);

		if (c == EOF || c == '\n')
		{
			if (size == 0 && c == EOF)
			{
				free(buffer);
				return (NULL);
			}
			break;
		}
		if (size >= capacity - 1)
		{
			capacity *= 2;
			buffer = realloc(buffer, capacity);

			if (!buffer)
			{
				perror("customFgets");
				return (NULL);
			}
		}
		buffer[size++] = (char)c;
	}
	buffer[size] = '\0';
	return (buffer);
}
