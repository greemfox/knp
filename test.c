#include "test.h"
#include "match.h"
#include <stdio.h>

Testificate tests[] = {
    {"a*", "", 1},	 {"a*", "a", 1},      {"a*", "aaa", 1},
    {"a*b", "b", 1},	 {"a*b", "ab", 1},    {"a*b", "aab", 1},
    {"ba*", "b", 1},	 {"ba*", "ba", 1},    {"ba*", "baa", 1},
    {"a*b", "a", 0},	 {"a*b", "tasty", 0}, {"a*b", "test", 0},
    {"a+", "a", 1},	 {"a+", "aaa", 1},    {"a+b", "ab", 1},
    {"a+b", "aab", 1},	 {"ba+", "ba", 1},    {"ba+", "baa", 1},
    {"a+", "", 0},	 {"a+", "b", 0},      {"a+b", "b", 0},
    {"a+b", "a", 0},	 {"ba+", "b", 0},     {"ba+", "a", 0},
    {"a?b", "ab", 1},	 {"a?b", "b", 1},     {"ba?b", "bb", 1},
    {"baa?", "ba", 1},	 {"baa?", "baa", 1},  {"a?bb", "bb", 1},
    {"ba?b", "baab", 0}, {"baaa?", "ba", 0},  {"aba?", "ba", 0},
};

int test(char *regex, char *text, int expected)
{
	char *yayornay = expected ? "..." : BLACK "not" COLOR_RESET;
	int pad = 6;
	printf(CYAN "%-*s" COLOR_RESET "should %s match" BLUE "%*s" COLOR_RESET,
	       pad, regex, yayornay, pad, text);
	if (match(regex, text) == expected) {
		puts(BOLD_GREEN "\tPassed!" COLOR_RESET);
	} else {
		puts(BOLD_RED "\tFailed!" COLOR_RESET);
		return 0;
	}
	return 1;
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
