#include "test.h"
#include "match.h"
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
    {"baaa?", "ba", false}, {"aba?", "ba", false},
};

bool test(char *regex, char *text, int expected)
{
	char *yayornay = expected ? "   " : BLACK "not" COLOR_RESET;
	int padding = 6;
	printf(CYAN "%-*s" COLOR_RESET "should %s match" BLUE "%*s" COLOR_RESET,
	       padding, regex, yayornay, padding, text);
	if (match(regex, text) == expected) {
		puts(BOLD_GREEN "\tPassed!" COLOR_RESET);
	} else {
		puts(BOLD_RED "\tFailed!" COLOR_RESET);
		return false;
	}
	return true;
}

int main(void)
{
	int total_tests = LEN(tests);
	for (int i = 0; i < total_tests; i++) {
		Testificate cur_test = tests[i];
		if (!test(cur_test.r, cur_test.t, cur_test.exp)) {
			break;
		}
	}
	return 0;
}
