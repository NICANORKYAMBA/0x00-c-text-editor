#include "text_editor.h"


void displayText(const TextContent *text)
{
	if (text == NULL)
		return;

	printf("%s", text->content);
	printf("\n");
}
