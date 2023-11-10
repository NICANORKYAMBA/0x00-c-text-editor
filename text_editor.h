#ifndef __TEXT_EDITOR_H_
#define __TEXT_EDITOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024


/**
 * struct Line - line of text in the text editor
 *
 * @text: text of the line in the text editor
 * @next: next line in the text editor
 */
typedef struct Line
{
	char *text;
	struct Line *next;
} Line;

/**
 * struct TextContent - text content of the text editor
 *
 * @firstLine: first line in the text editor
 * @lastLine: last line in the text editor
 * @numLines: number of lines in the text editor
 * @cursorCol: cursor column in the text editor
 * @cursorRow: cursor row in the text editor
 */
typedef struct TextContent
{
	Line *firstLine;
	Line *lastLine;
	int numLines;
	int cursorCol;
	int cursorRow;
} TextContent;

void initializeTextEditor(TextContent *text);

void displayText(const TextContent *text);

void cleanupTextEditor(TextContent *editor);

void insertText(TextContent *text, int position, const char *line);

void deleteText(TextContent *text, int position, int length);

void saveTextToFile(const TextContent *text, const char *fileName);

void loadTextFromFile(TextContent *text, const char *fileName);

void editText(TextContent *text, int position, const char *newText);

void moveCursor(TextContent *text, char direction);

int getCurrentCol(TextContent *text);

int getCurrentRow(TextContent *text);

int getLineLength(TextContent *text, int numLines);

int getCurrentPosition(TextContent *text);

void appendText(TextContent *text, const char *line);
void prependText(TextContent *text, const char *line);
void replaceText(TextContent *text, int position, const char *line);
void clearText(TextContent *text);
void deleteWord(TextContent *text, int position);
void insertWord(TextContent *text, int position);
void moveWord(TextContent *text, int direction);
void moveLine(TextContent *text, int direction);
void moveCursorToEndOfLine(TextContent *text);
void moveCursorToStartOfLine(TextContent *text);
void moveCursorToStartOfWord(TextContent *text);
void moveCursorToEndOfWord(TextContent *text);
void moveCursorToStartOfText(TextContent *text);
void moveCursorToEndOfText(TextContent *text);
void moveCursorToStartOfScreen(TextContent *text);
void moveCursorToEndOfScreen(TextContent *text);
void moveCursorToStartOfDocument(TextContent *text);
void moveCursorToEndOfDocument(TextContent *text);
void moveCursorToStartOfSelection(TextContent *text);
void moveCursorToEndOfSelection(TextContent *text);
void moveCursorToStartOfLineSelection(TextContent *text);
void moveCursorToEndOfLineSelection(TextContent *text);

#endif
