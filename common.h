/* common.h contains the most used libraries to reduce #includes in other files */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

/* FUNCTION DECLARATIONS */

void print_credits();

int get_selection(const char *strings[]);

void print_main_title();
