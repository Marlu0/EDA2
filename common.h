/* common.h contains the most used libraries to reduce #includes in other files */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

/* Global variables */

#define MAX_SKILLS 4
#define MAX_MODIFIERS 4
#define MAX_STRING_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_OPTIONS 2
#define MAX_DECISIONS 2

/* FUNCTION DECLARATIONS */

void print_credits();

int get_selection(const char *strings[]);

void print_main_title();
