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
#define cls()                   printf(CLEAR_SCREEN)
#define MARGIN_LEN(w, t)        (w - strlen(t)) / 2
#define BLANK_CHAR              "x"
#define LINES_LEFT(q)           SCREEN_HEIGHT - NOT_BODY_LINES - q

// indexing
#define NUMMED_SUBSEC           "%s.\t%s"
#define INT_LEN(i)              floor(log10(fabs(i))) + 1

#define UPPER_A_ASCII           65
#define UPPER_Z_ASCII           90
#define LOWER_A_ASCII           97
#define LOWER_Z_ASCII           122
////////////////////////////////////////

// menus
void write_subsec_menu(struct Container, struct Body, struct Container);

// print container
char* get_cont_str(char*, struct Container);

// print body
void print_body(int, struct Body);
void print_subsec(int, struct Body);
void print_blank_line(int);

// lower lv functions
char* center(char*, const char*, int, char);
char* trans_index(char*, index_type, int);

#endif // SCREEN_H