#include "text_editor.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *input = NULL;
	size_t inputSize = 0;

	TextContent text_content;

	initializeTextEditor(&text_content);

	while (1)
	{
		printf("\nEnter a command (or q to quit): ");

		if (getline(&input, &inputSize, stdin) == -1 || strcmp(input, "q\n") == 0 ||
				strcmp(input, "quit\n") == 0)
		{
			break;
		}

		processCommand(&text_content, input);
	}

	free(input);
	cleanupTextEditor(&text_content);

	return (0);
}
