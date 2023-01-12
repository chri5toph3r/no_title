#ifndef INC_STDIO_H
#define INC_STDIO_H
#include <stdio.h>
#endif // INC_STDIO_H

#ifndef INC_STR_H
#define INC_STR_H
#include <string.h>
#endif // INC_STR_H

#ifndef INC_MATH_H
#define INC_MATH_H
#include <math.h>
#endif // INC_MATH_H

////////////////////////////////////////
#ifndef INC_TYPES_H
#define INC_TYPES_H
#include "types.h"
#endif // INC_TYPES_H

////////////////////////////////////////
////////////////////////////////////////
#ifndef SCREEN_H
#define SCREEN_H

#ifndef SCREEN_DIMS
#define SCREEN_DIMS

#define SCREEN_WIDTH    50
#define SCREEN_HEIGHT   10
#endif // SCREEN_DIMS
////////////////////////////////////////

// general
#define CLEAR_SCREEN            "\e[1;1H\e[2J"
#define MARGIN_LEN(w, t)        (w - strlen(t)) / 2
#define FILL_CHAR               "x"
#define NOT_BODY_LINES          2
#define IS_N_FILLED(q)          (SCREEN_HEIGHT - NOT_BODY_LINES - q) > 0

// indexing
#define NUMMED_SUBSEC(i, t)     "%s.\t%s", i, t
#define INT_LEN(i)              5// floor(log10(fabs(i))) + 1

#define UPPER_A_ASCII           65
#define UPPER_Z_ASCII           90
#define LOWER_A_ASCII           97
#define LOWER_Z_ASCII           122
////////////////////////////////////////

typedef enum {
    arabic_num,
    roman_upp_num,
    roman_low_num,
    upp_alpha,
    low_alpha
} index_type;

struct body {
    int subsec_quan;
    labels subsec;
    index_type style;
    int start_index;
};

void write_menu(const char*, struct body, const char*);
void center_print(const char*, int, char);
char* trans_index(index_type, int, char*);

#endif // SCREEN_H