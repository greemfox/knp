#include "test.h"
#include "match.c"
#include <stdio.h>

Testificate tests[] = {
    {"a*", "", true},	    {"a*", "a", true},	     {"a*", "aaa", true},
    {"a*b", "b", true},	    {"a*b", "ab", true},     {"a*b", "aab", true},
    {"ba*", "b", true},	    {"ba*", "ba", true},     {"ba*", "baa", true},
    {"a*b", "a", false},    {"a*b", "tasty", false}, {"a*b", "test", false},
    {"a+", "a", true},	    {"a+", "aaa", true},     {"a+b", "ab", true},
    {"a+b", "aab", true},   {"ba+", "ba", true},     {"ba+", "baa", true},
    {"a+", "", false},	    {"a+", "b", false},	     {"a+b", "b", false},
    {"a+b", "a", false},    {"ba+", "b", false},     {"ba+", "a", false},
    {"a?b", "ab", true},    {"a?b", "b", true},	     {"ba?b", "bab", true},
    {"ba?b", "bb", true},   {"baa?", "ba", true},    {"baa?", "baa", true},
    {"a?bb", "bb", true},   {"a?bb", "abb", true},   {"ba?b", "baab", false},
    {"baaa?", "ba", false}, {"aba?", "ba", false},   {"/$", "$", true},
    {"/$$", "$", true},	    {"/*", "*", true},	     {"/+", "+", true},
    {"/?", "?", true},	    {"a/+*b", "ab", true},   {"a/++b", "a+++b", true},
    {"/a", "a", false},	    {"/$$", "$a", false},
};

bool test(char *regex, char *text, int expected)
{
	char *yayornay = expected ? "   " : BLACK "not" RESET;
	int padding = 6;
	printf(CYAN "%-*s" RESET "should %s match" BLUE "%*s" RESET, padding,
	       regex, yayornay, padding, text);
	if (match(regex, text) == expected) {
		puts(BOLD_GREEN " Passed!" RESET);
	} else {
		puts(BOLD_RED " Failed!" RESET);
		return false;
	}
	return true;
}

int main(void)
{
	int total_tests = LEN(tests);
	for (int i = 0; i < total_tests; i++) {
		Testificate cur_test = tests[i];
		if (!test(cur_test.re, cur_test.text, cur_test.expected)) {
			break;
		}
	}
	return 0;
}
