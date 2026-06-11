#include "match.h"
#include <stdio.h>

/* The Rob Pike Subset:
 * '^' matches the beginning of input
 * '$' matches the end
 * '.' matches any single character
 * '*' matches 0 or more occurrences of the previous char
 * 'c' matches any literal character c
 */

/* Extensions:
 * [x]  '+' matches 1 or more occurrences of the previous char
 * [ ]  '?' matches 0 or 1 occurrence of the previous char
 * [ ] '\d' matches a digit
 * [ ] '\D' matches a nondigit
 * [ ] '\s' matches whitespace
 * [ ] '\S' matches non-whitespace
 * [ ]  '\' quotes the following metacharacter
 */

int main(int argc, char **argv)
{
	if (argc != 3) {
		puts("Usage: match <regex> <text>\n"
		     "Don't forget to escape globs.");
		return -1;
	}
	if (match(argv[1], argv[2])) {
		puts("Found");
	} else {
		puts("Not found");
	}
	return 0;
}
