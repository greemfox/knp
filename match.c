#include "match.h"
#include <stdio.h>

/* The Rob Pike Subset:
 * ^ matches the beginning of input
 * $ matches the end
 * . matches any single character
 * * matches 0 or more occurrences of the previous char
 * c matches any literal character c
 */

/* Extensions:
 * [ ]  + matches 1 or more occurrences of the previous char
 * [ ]  ? matches 0 or 1 occurrence of the previous char
 * [ ] \d matches a digit
 * [ ] \D matches a nondigit
 * [ ] \s matches whitespace
 * [ ] \S matches non-whitespace
 * [ ]  \ quotes the following metacharacter
 */

/* Looks for a match anywhere within text. */
int match(char *regex, char *text)
{
	if (regex[0] == '^')
		matchhere(regex + 1, text);
	do {
		if (matchhere(regex, text))
			return 1;
	} while (*text++ != '\0');
	return 0;
}

/* Looks for a match at the beginning of text. */
int matchhere(char *regex, char *text)
{
	if (regex[0] == '\0')
		return 1;
	if (regex[0] == '$' && regex[1] == '\0')
		return *text == '\0';
	switch (regex[1]) {
	case '*':
		return matchstar(regex[0], regex + 2, text);
	case '+':
		return matchplus(regex[0], regex + 2, text);
	case '?':
		return matchqmrk(regex[0], regex + 2, text);
	}
	if (*text != '\0' && (regex[0] == '.' || regex[0] == text[0]))
		return matchhere(regex + 1, text + 1);
	return 0;
}

/* Looks for c*regex at the beginning of text. */
int matchstar(char c, char *regex, char *text)
{
	do {
		if (matchhere(regex, text))
			return 1;
	} while (*text != '\0' && (*text++ == c || c == '.'));
	return 0;
}

/* Looks for c+regex at the beginning of text. */
int matchplus(char c, char *regex, char *text)
{
	return 0;
}

/* Looks for c?regex at the beginning of text. */
int matchqmrk(char c, char *regex, char *text)
{
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 3) {
		puts("Usage: match <regex> <text>\n"
		     "Don't forget to escape globs.");
		return 1;
	}
	if (match(argv[1], argv[2]) == 1)
		puts("Found");
	else
		puts("Not found");
	return 0;
}
