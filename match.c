#include "match.h"

/* Looks for a match anywhere within text. */
bool match(char *regex, char *text)
{
	if (regex[0] == '^') {
		matchhere(regex + 1, text);
	}
	do {
		if (matchhere(regex, text)) {
			return true;
		}
	} while (*text++ != '\0');
	return false;
}

/* Looks for a match at the beginning of text. */
bool matchhere(char *regex, char *text)
{
	if (regex[0] == '\0') {
		return true;
	}
	if (regex[0] == '$' && regex[1] == '\0') {
		return *text == '\0';
	}
	if (regex[0] == '\\' && regex[1] != '\0') {
		return escapechar(regex + 1, text);
	}
	switch (regex[1]) {
	case '*':
		return matchstar(regex[0], regex + 2, text);
	case '+':
		return matchplus(regex[0], regex + 2, text);
	case '?':
		return matchqmark(regex[0], regex + 2, text);
	}
	if (*text != '\0' && (regex[0] == '.' || regex[0] == text[0])) {
		return matchhere(regex + 1, text + 1);
	}
	return false;
}

/* Looks for c*regex at the beginning of text. */
bool matchstar(char c, char *regex, char *text)
{
	do {
		if (matchhere(regex, text)) {
			return true;
		}
	} while (*text != '\0' && (*text++ == c || c == '.'));
	return false;
}

/* Looks for c+regex at the beginning of text. */
bool matchplus(char c, char *regex, char *text)
{
	while (*text != '\0' && (*text++ == c || c == '.')) {
		if (matchhere(regex, text)) {
			return true;
		}
	}
	return false;
}

/* Looks for c?regex at the beginning of text. */
bool matchqmark(char c, char *regex, char *text)
{
	if (matchhere(regex, text) ||
	    (*text == c && matchhere(regex, text + 1))) {
		return true;
	}
	return false;
}

/* Handles escapement. */
bool escapechar(char *regex, char *text)
{
	switch (regex[0]) {
	case '$':
	case '*':
	case '+':
	case '?':
	case '\\':
		return matchhere(regex, text);
	}
	return false;
}
