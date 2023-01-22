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

// printing
#define CLEAR_SCREEN            "\e[1;1H\e[2J"
#define cls()                   printf(CLEAR_SCREEN)
#define BLANK_CHAR              "x"

// indexing
#define INT_LEN(i)              floor(log10(fabs(i))) + 1

#define UPPER_A_ASCII           65
#define UPPER_Z_ASCII           90
#define LOWER_A_ASCII           97
#define LOWER_Z_ASCII           122

// margins
#define R_MARGIN_LEN(w, t)      w - strlen(t)
#define C_MARGIN_LEN(w, t)      (w - strlen(t)) / 2
////////////////////////////////////////

// menu
void write_menu(container, area, container);

/*
TODO: prints take as arg and return char* /
which is declared as char[SCREEN_HEIGHT][SCREEN_WIDTH]
TODO: can work like:
mentioned array is global, every function adds to it,
at the end of write_menu function, 
simple printing of that array occurrs
*/
// prints
void print_area(int, area);                     // !: changed
// void print_container(char*, container);      // !: changed
void print_container(container);                // !: changed
void print_item(item, int, index_type);         // !: changed order
char* trans_index(char*, int, index_type);      // !: changed order
void print_blank_line(int);

// TODO: might as well be in separate file 
// alignment
char* get_aligned(char*, int, char*, align, char);
char* align_right(char*, int, char*, char);         // !: changed order
char* center(char*, int, char*, char);              // !: changed order
char* get_margin(char*, int, char);                 // !: changed order

#endif // SCREEN_H