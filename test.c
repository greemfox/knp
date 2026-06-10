#include "test.h"
#include "match.h"
#include <stdio.h>

Testificate tests[] = {
    {"a*", "", 1},     {"a*", "a", 1},	    {"a*", "aaa", 1},
    {"a*b", "b", 1},   {"a*b", "ab", 1},    {"a*b", "aab", 1},
    {"ba*", "b", 1},   {"ba*", "ba", 1},    {"ba*", "baa", 1},
    {"a*b", "a", 0},   {"a*b", "tasty", 0}, {"a*b", "test", 0},
    {"a+", "a", 1},    {"a+", "aaa", 1},    {"a+b", "ab", 1},
    {"a+b", "aab", 1}, {"ba+", "ba", 1},    {"ba+", "baa", 1},
    {"a+", "", 0},     {"a+", "b", 0},	    {"a+b", "b", 0},
    {"a+b", "a", 0},   {"ba+", "b", 0},	    {"ba+", "a", 0},
};

int test(char *regex, char *text, int expected)
{
	char *yayornay = expected ? "..."
				  : "\e[0;30m"
				    "not"
				    "\e[0m";
	int pad = 6;
	printf("\e[0;36m"
	       "%-*s"
	       "\e[0m"
	       "should %s match"
	       "\e[0;34m"
	       "%*s"
	       "\e[0m",
	       pad, regex, yayornay, pad, text);
	if (match(regex, text) == expected) {
		puts("\e[1;32m"
		     "\tPassed!"
		     "\e[0m");
	} else {
		puts("\e[1;31m"
		     "\tFailed!"
		     "\e[0m");
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
