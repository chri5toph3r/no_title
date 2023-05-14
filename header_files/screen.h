#ifndef INC_MATH_H
#define INC_MATH_H
#include <math.h>
#endif // INC_MATH_H

#ifndef INC_STDIO_H
#define INC_STDIO_H
#include <stdio.h>
#endif // INC_STDIO_H

#ifndef INC_STR_H
#define INC_STR_H
#include <string.h>
#endif // INC_STR_H

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
void write_menu(container*, area*, container*);

/*
TODO: prints take as arg and return char* /
which is declared as char[SCREEN_HEIGHT][SCREEN_WIDTH]
TODO: can work like:
mentioned array is global, every function adds to it,
at the end of write_menu function, 
simple printing of that array occurrs
*/
// prints
char** get_area(char**, area*);                     // !: changed
// void print_container(char*, container);      // !: changed
char** get_container(char**, container*);                // !: changed 
char** get_item(char**, item*);         // !: changed
char* trans_index(char*, int, index_type*);      // !: changed order
char* get_blank_line(char*, int, char);

// screen functions
int update_screen(char**, int);
void refresh_screen();
int setup_screen();

// TODO: might as well be in separate file 
// alignment
char* get_aligned(char*, int, char*, alignment*);
char* align_right(char*, int, char*, char);         // !: changed order
char* center(char*, int, char*, char);              // !: changed order
char* get_margin(char*, int, char);                 // !: changed order

char *screen[SCREEN_HEIGHT];
int screen_line;

#endif // SCREEN_H