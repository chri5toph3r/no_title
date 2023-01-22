#ifndef INC_TYPES_H
#define INC_TYPES_H
#include "types.h"
#endif // INC_TYPES_H

#ifndef INC_SCREEN_H
#define INC_SCREEN_H
#include "screen.h"
#endif // INC_SCREEN_H

////////////////////////////////////////
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#define MM_T_WIDTH          SCREEN_WIDTH
#define MM_T_HEIGHT         1       // TODO: make it 3 and work
#define MM_T_TXTS_Q         1
#define MM_T_TXT            "'THE MENU MANAGER'"
#define MM_T_ALIGN          CENTER
#define MM_T_SEP            '.'

#define MM_B_HEIGHT         3
#define MM_B_C_HEIGHT       1
#define MM_B_OPT_QUAN       3
#define MM_B_C_TXT_QUAN     1
#define MM_B_DEFAULT_TOP    0
#define MM_B_ALIGN          CENTER
#define MM_B_SEP            '.'
#define MM_B_STYLE          NONE


item title_item;
container mm_title;

item mm_texts[MM_B_OPT_QUAN];
container mm_options[MM_B_OPT_QUAN];
area mm_body;

container mm_footer;

int _main_menu();

#endif // MAIN_MENU_H