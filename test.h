#define LEN(arr) (sizeof(arr) / sizeof(arr[0]))

#define BLACK "\e[0;30m"
#define BLUE "\e[0;34m"
#define CYAN "\e[0;36m"
#define BOLD_RED "\e[1;31m"
#define BOLD_GREEN "\e[1;32m"
#define COLOR_RESET "\e[0m"

typedef struct {
	char *r;
	char *t;
	int exp;
} Testificate;
