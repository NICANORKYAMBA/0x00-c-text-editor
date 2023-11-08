#include "text_editor.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char input[100];
	int position;
	int length;
	char file_name[100];

	TextContent text_content;

	initializeTextEditor(&text_content);

	while (1)
	{
		displayText(&text_content);

		printf("Enter a command (or q to quit): ");
		fgets(input, sizeof(input), stdin);
		input[strlen(input) - 1] = '\0';
		printf("\n");

		if (strcmp(input, "q") == 0)
		{
			break;
		}
		else if (strcmp(input, "i") == 0)
		{
			printf("Enter the text to insert and its position: ");
			scanf("%s %d", input, &position);
			fgets(input, sizeof(input), stdin);
			input[strlen(input) - 1] = '\0';
			insertText(&text_content, position, input);
		}
		else if (strcmp(input, "d") == 0)
		{
			printf("Enter the position to delete and length: ");
			scanf("%d %d", &position, &length);
			deleteText(&text_content, position, length);
		}
		else if (strcmp(input, "w") == 0)
		{
			printf("Enter the text to write and file name: ");
			scanf("%s %s", input, file_name);
			saveTextToFile(&text_content, file_name);
		}
		else if (strcmp(input, "s") == 0)
		{
			printf("Enter the position to search: ");
			scanf("%d", &position);
			searchText(&text_content, position);
		}
		else
		{
			printf("Invalid command\n");
		}

	}
	
	cleanupTextEditor(&text_content);

	return 0;
}
